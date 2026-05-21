#include "..\..\Headers\Service\CamionistaService.h"
#include "..\..\Headers\Model\Rota.h"
#include "..\..\Headers\Model\Localidade.h"
#include "..\..\Headers\Dtos\RotaDTO.h"
#include <stdexcept>

CamionistaService::CamionistaService(CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer){
    this->camionistaContainer= camionistaContainer;
    this->cargaContainer= cargaContainer;
    this->rotaContainer= rotaContainer;
}

bool CamionistaService::verificarLogin(std::string nome){
    Camionista *c = camionistaContainer->procurar(nome);
    if(c != nullptr){
        return true;
    }
    return false;

}


CamiaoDTO CamionistaService::visualizarEstadoCamiao(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    Camiao* camiao = camionista->getCamiao();
    
    CamiaoDTO dto;
    dto.capacidadeMaxima = camiao->getCapacidadeMaxima();
    dto.capacidadeDisponivel = camiao->getCapacidadeDisponivel();
    
    // preenche as cargas
    std::vector<Carga*>& cargas = camiao->getCargas();
    for(int i = 0; i < cargas.size(); i++){
        dto.cargas.push_back(cargas[i]->getDestino()->getNome()); //localidade e depois nome
    }//->getDestino()   → devolve Localidade*
//->getNome()      → devolve string com o nome da localidade

    
    return dto;
}

std::vector<CargaDTO> CamionistaService::getCargasDoCamiao(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    Camiao* camiao = camionista->getCamiao();
    
    std::vector<Carga*>& cargas = camiao->getCargas();
    std::vector<Carga>& todas = cargaContainer->getTodos();
    std::vector<CargaDTO> dtos;
    
    // para cada carga do camião, descobrir o seu índice no container
    for(int i = 0; i < cargas.size(); i++){
        for(int j = 0; j < todas.size(); j++){
            if(cargas[i] == &todas[j]){
                CargaDTO dto;
                dto.indice = j;
                dto.peso = cargas[i]->getPeso();
                dto.nomeDestino = cargas[i]->getDestino()->getNome();
                dto.estado = cargas[i]->getEstado();
                dtos.push_back(dto);
                break;
            }
        }
    }
    
    return dtos;
}
 
void CamionistaService::removerCarga(std::string nomeCamionista, int indiceCarga){
    // 1. Obter camionista e camião
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    Camiao* camiao = camionista->getCamiao();
    
    // 2. Obter a carga pelo índice
    Carga* carga = cargaContainer->procurar(indiceCarga);
    if(carga == nullptr){
        throw std::invalid_argument("Carga inexistente.");
    }
    
    // 3. Validar que a carga está mesmo no camião
    std::vector<Carga*>& cargasDoCamiao = camiao->getCargas();
    bool encontrada = false;
    for(int i = 0; i < cargasDoCamiao.size(); i++){
        if(cargasDoCamiao[i] == carga){
            encontrada = true;
            break;
        }
    }
    if(!encontrada){
        throw std::invalid_argument("Carga não está atribuída a este camião.");
    }
    
    // 4. Remover do camião
    camiao->removerCarga(carga);
    
    // 5. Devolver peso à capacidade disponível
    float novaCapacidade = camiao->getCapacidadeDisponivel() + carga->getPeso();
    camiao->setCapacidadeDisponivel(novaCapacidade);
    
    // 6. Estado da carga volta a "Disponivel"
    carga->setEstado("Disponivel");
}

RotaDTO CamionistaService::calcularRota(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    Camiao* camiao = camionista->getCamiao();
    std::vector<Carga*>& cargas = camiao->getCargas();
    
    if(cargas.empty()){
        throw std::invalid_argument("O camiao nao tem cargas atribuidas.");
    }
    
    // Empresa parte da localizacao (0,0)
    Localidade empresa("Empresa", 0.0f, 0.0f);
    
    // Calcular distancia total FIFO
    float distanciaTotal = 0.0f;
    Localidade* anterior = &empresa;
    
    RotaDTO dto;
    dto.nomeCamionista = nomeCamionista;
    dto.matriculaCamiao = camiao->getMatricula();
    
    for(int i = 0; i < cargas.size(); i++){
        Localidade* destino = cargas[i]->getDestino();
        distanciaTotal += anterior->calcularDistancia(*destino);
        dto.destinosOrdemFIFO.push_back(destino->getNome());
        anterior = destino;
    }
    
    dto.distanciaTotal = distanciaTotal;
    dto.idRota = rotaContainer->getTodos().size() + 1;
    
    return dto;
}
 
void CamionistaService::iniciarEntrega(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    Camiao* camiao = camionista->getCamiao();
    std::vector<Carga*>& cargas = camiao->getCargas();
    
    if(cargas.empty()){
        throw std::invalid_argument("O camiao nao tem cargas atribuidas.");
    }
    
    // 1. Calcular distancia total (igual ao calcularRota)
    Localidade empresa("Empresa", 0.0f, 0.0f);
    float distanciaTotal = 0.0f;
    Localidade* anterior = &empresa;
    for(int i = 0; i < cargas.size(); i++){
        Localidade* destino = cargas[i]->getDestino();
        distanciaTotal += anterior->calcularDistancia(*destino);
        anterior = destino;
    }
    
    // 2. Criar copia das cargas (Rota guarda por valor)
    std::vector<Carga> cargasParaRota;
    for(int i = 0; i < cargas.size(); i++){
        cargasParaRota.push_back(*cargas[i]);
    }
    
    // 3. Atualizar estado das cargas para "Entregue"
    for(int i = 0; i < cargas.size(); i++){
        cargas[i]->setEstado("Entregue");
    }
    
    // 4. Criar e guardar a Rota
    int idRota = rotaContainer->getTodos().size() + 1;
    Rota rota(idRota, nomeCamionista, camiao->getMatricula(), distanciaTotal, cargasParaRota);
    rotaContainer->guardar(rota);
    
    // 5. Desvincular camionista do camiao
    camionista->setCamiao(nullptr);
    camionista->setEstado("Disponivel");
    
    // 6. Camiao volta a "Disponivel"
    camiao->setEstado("Disponivel");
    camiao->setCamionista(nullptr);
    
    // 7. Limpar cargas do camiao e devolver capacidade total
    while(!camiao->getCargas().empty()){
        camiao->removerCarga(camiao->getCargas()[0]);
    }
    camiao->setCapacidadeDisponivel(camiao->getCapacidadeMaxima());
}
