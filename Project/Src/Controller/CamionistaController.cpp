#include "..\..\Headers\Controller\CamionistaController.h"
#include "..\..\Headers\Model\CamiaoDTO.h"
CamionistaController::CamionistaController(CamionistaService *service) {
    this->service = service;
}


bool CamionistaController::verificarLogin(std::string nome) {
    return service->verificarLogin(nome); //chama o servico, é um intermediario
}

CamiaoDTO CamionistaController::visualizarEstadoCamiao(std::string nomeCamionista){
    return service->visualizarEstadoCamiao(nomeCamionista);
}

