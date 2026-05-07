#include "Project\Headers\Controller\CamionistaController.h"

CamionistaController::CamionistaController(CamionistaService* service) {
    this->service = service;
}


bool CamionistaController::verificarLogin(std::string nome) {
    return service->verificarLogin(nome); //chama o servico, é um intermediario
}
