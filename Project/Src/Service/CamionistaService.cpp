#include "Project\Headers\Service\CamionistaService.h"

CamionistaService::CamionistaService(CamionistaContainer *container){
    this->container = container;
}

bool CamionistaService::verificarLogin(std::string nome){
    Camionista *c = container->procurar(nome);
    if(c != nullptr){
        return true;
    }
    return false;

}


CamiaoDTO CamionistaService::visualizarEstadoCamiao(std::string nomeCamionista){
    Camionista* camionista = container->procurar(nomeCamionista);
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