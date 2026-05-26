#include "..\..\Headers\Service\CamionistaService.h"
#include "..\..\Headers\Model\Rota.h"
#include "..\..\Headers\Model\Localidade.h"
#include "..\..\Headers\Dtos\RotaDTO.h"
#include <stdexcept>

// Construtor: recebe ponteiros para os 3 containers que o service precisa
CamionistaService::CamionistaService(CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer){
    this->camionistaContainer = camionistaContainer;
    this->cargaContainer = cargaContainer;
    this->rotaContainer = rotaContainer;
}

// Verifica se um camionista existe no sistema com o nome dado
bool CamionistaService::verificarLogin(std::string nome){
    Camionista *c = camionistaContainer->procurar(nome);
    if(c != nullptr){
        return true;
    }
    return false;
}

// Devolve um DTO com a informacao do camiao atribuido ao camionista
CamiaoDTO CamionistaService::visualizarEstadoCamiao(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    // Validacao: o camionista tem de ter um camiao atribuido
    if(camionista->getCamiao() == nullptr){
        throw std::invalid_argument("Nao tem camiao atribuido. Contacte o gestor.");
    }
    
    Camiao* camiao = camionista->getCamiao();
    
    // Cria o DTO que vai transportar os dados para a view
    CamiaoDTO dto;
    dto.capacidadeMaxima = camiao->getCapacidadeMaxima();
    dto.capacidadeDisponivel = camiao->getCapacidadeDisponivel();
    
    // Preenche a lista de cargas atribuidas (nome do destino de cada uma)
    std::vector<Carga*>& cargas = camiao->getCargas();
    for(int i = 0; i < cargas.size(); i++){
        dto.cargas.push_back(cargas[i]->getDestino()->getNome());
    }
    
    return dto;
}

// Devolve a lista de cargas que estao disponiveis no sistema
std::vector<CargaDTO> CamionistaService::getCargasDisponiveis(){
    std::vector<Carga>& todas = cargaContainer->getTodos();
    std::vector<CargaDTO> dtos;
    
    // Percorre todas as cargas e filtra apenas as disponiveis
    for(int i = 0; i < todas.size(); i++){
        if(todas[i].getEstado() == "Disponivel"){
            CargaDTO dto;
            dto.indice = i;
            dto.peso = todas[i].getPeso();
            dto.nomeDestino = todas[i].getDestino()->getNome();
            dto.estado = todas[i].getEstado();
            dtos.push_back(dto);
        }
    }
    
    return dtos;
}

// Adiciona uma carga ao camiao do camionista
void CamionistaService::adicionarCarga(std::string nomeCamionista, int indiceCarga){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    // Validacao: o camionista tem de ter um camiao atribuido
    if(camionista->getCamiao() == nullptr){
        throw std::invalid_argument("Nao tem camiao atribuido. Contacte o gestor.");
    }
    
    Camiao* camiao = camionista->getCamiao();
    Carga* carga = cargaContainer->procurar(indiceCarga);
    
    // Validacao 1: a carga tem de existir
    if(carga == nullptr){
        throw std::invalid_argument("Carga inexistente.");
    }
    
    // Validacao 2: a carga tem de estar disponivel
    if(carga->getEstado() != "Disponivel"){
        throw std::invalid_argument("Carga ja nao esta disponivel.");
    }
    
    // Validacao 3: o peso nao pode exceder a capacidade do camiao
    if(carga->getPeso() > camiao->getCapacidadeDisponivel()){
        throw std::invalid_argument("Peso da carga excede a capacidade disponivel.");
    }
    
    float novaCapacidade = camiao->getCapacidadeDisponivel() - carga->getPeso();
    camiao->setCapacidadeDisponivel(novaCapacidade);
    camiao->adicionarCarga(carga);
    carga->setEstado("Atribuida");
}

// Devolve a lista de cargas que estao no camiao do camionista
std::vector<CargaDTO> CamionistaService::getCargasDoCamiao(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    // Validacao: o camionista tem de ter um camiao atribuido
    if(camionista->getCamiao() == nullptr){
        throw std::invalid_argument("Nao tem camiao atribuido. Contacte o gestor.");
    }
    
    Camiao* camiao = camionista->getCamiao();
    std::vector<Carga*>& cargas = camiao->getCargas();
    std::vector<Carga>& todas = cargaContainer->getTodos();
    std::vector<CargaDTO> dtos;
    
    // Para cada carga do camiao, descobrir o seu indice no container global
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

// Remove uma carga do camiao do camionista
void CamionistaService::removerCarga(std::string nomeCamionista, int indiceCarga){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    // Validacao: o camionista tem de ter um camiao atribuido
    if(camionista->getCamiao() == nullptr){
        throw std::invalid_argument("Nao tem camiao atribuido. Contacte o gestor.");
    }
    
    Camiao* camiao = camionista->getCamiao();
    Carga* carga = cargaContainer->procurar(indiceCarga);
    
    // Validacao: a carga tem de existir
    if(carga == nullptr){
        throw std::invalid_argument("Carga inexistente.");
    }
    
    // Validacao: a carga tem de estar no camiao
    std::vector<Carga*>& cargasDoCamiao = camiao->getCargas();
    bool encontrada = false;
    for(int i = 0; i < cargasDoCamiao.size(); i++){
        if(cargasDoCamiao[i] == carga){
            encontrada = true;
            break;
        }
    }
    if(!encontrada){
        throw std::invalid_argument("Carga nao esta atribuida a este camiao.");
    }
    
    camiao->removerCarga(carga);
    float novaCapacidade = camiao->getCapacidadeDisponivel() + carga->getPeso();
    camiao->setCapacidadeDisponivel(novaCapacidade);
    carga->setEstado("Disponivel");
}

// Calcula a rota sem alterar estado do sistema
RotaDTO CamionistaService::calcularRota(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    // Validacao: o camionista tem de ter um camiao atribuido
    if(camionista->getCamiao() == nullptr){
        throw std::invalid_argument("Nao tem camiao atribuido. Contacte o gestor.");
    }
    
    Camiao* camiao = camionista->getCamiao();
    std::vector<Carga*>& cargas = camiao->getCargas();
    
    // Validacao: tem de haver cargas para entregar
    if(cargas.empty()){
        throw std::invalid_argument("O camiao nao tem cargas atribuidas.");
    }
    
    // A empresa parte da localizacao (0,0)
    Localidade empresa("Empresa", 0.0f, 0.0f);
    float distanciaTotal = 0.0f;
    Localidade* anterior = &empresa;
    
    RotaDTO dto;
    dto.nomeCamionista = nomeCamionista;
    dto.matriculaCamiao = camiao->getMatricula();
    
    // Percorre as cargas pela ordem FIFO e calcula distancia total
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

// Executa a entrega e atualiza todos os estados
void CamionistaService::iniciarEntrega(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    // Validacao: o camionista tem de ter um camiao atribuido
    if(camionista->getCamiao() == nullptr){
        throw std::invalid_argument("Nao tem camiao atribuido.");
    }
    
    Camiao* camiao = camionista->getCamiao();
    std::vector<Carga*>& cargas = camiao->getCargas();
    
    if(cargas.empty()){
        throw std::invalid_argument("O camiao nao tem cargas atribuidas.");
    }
    
    // 1. Calcular distancia total
    Localidade empresa("Empresa", 0.0f, 0.0f);
    float distanciaTotal = 0.0f;
    Localidade* anterior = &empresa;
    for(int i = 0; i < cargas.size(); i++){
        Localidade* destino = cargas[i]->getDestino();
        distanciaTotal += anterior->calcularDistancia(*destino);
        anterior = destino;
    }
    
    // 2. Criar copia das cargas para a Rota
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
