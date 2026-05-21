#include "..\..\Headers\Service\CamionistaService.h"
#include <stdexcept>

CamionistaService::CamionistaService(CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer){
    this->camionistaContainer= camionistaContainer;
    this->cargaContainer= cargaContainer;
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