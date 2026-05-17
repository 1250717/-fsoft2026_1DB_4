#include "..\..\Headers\Controller\CamionistaController.h"
#include "..\..\Headers\Model\CamiaoDTO.h"
#include "..\..\Headers\View\MenuCamionista.h"

CamionistaController::CamionistaController(CamionistaService *service) {
    this->service = service;
}

bool CamionistaController::verificarLogin(std::string nome) {
    return service->verificarLogin(nome); //chama o servico, é um intermediario
}

CamiaoDTO CamionistaController::visualizarEstadoCamiao(std::string nomeCamionista){
    return service->visualizarEstadoCamiao(nomeCamionista);
}

void CamionistaController::mostrarMenu(){
    std::string nome = menu.pedirNome(); // Camionista controller tem atributo menu que é MenuCamionista
    
    if(service->verificarLogin(nome)){
        while(true){
            int opcao = menu.mostrarOpcoes();  // recebe opcao
            
            if(opcao == 0) break;
            else if(opcao == 1){ // visualizar estado camiao
                CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                menu.mostrarEstadoCamiao(camiao);  // passa ao menu para mostrar
            }
        }
    }
}