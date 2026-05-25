#include "..\..\Headers\Controller\GestorController.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CamionistaDTO.h"
#include <iostream>

GestorController::GestorController(GestorService *service){
    this->service = service;
}

void GestorController::mostrarMenu(){
    nomeGestor = menu.pedirNomeGestor();
    while(true){
        int opcao = menu.mostrarOpcoes();

        if(opcao == 0){
            break;
        }
        else if(opcao == 1){
            std::string matricula = menu.pedirMatricula();
            float capacidadeMaxima = menu.pedirCapacidadeMaxima();
            try{
                service->registrarCamiao(matricula, capacidadeMaxima);
                std::vector<CamiaoDTO> camioes = service->getTodosCamioes();
                menu.mostrarSucessoRegistarCamiao(camioes);
            }
            catch(std::invalid_argument &e){
                menu.mostrarErro(e.what());
            }
        }
        else if(opcao == 2){
            std::string nomeCamionista = menu.pedirNomeCamionista();
            try{
                service->registrarCamionista(nomeCamionista);
                std::vector<CamionistaDTO> camionistas = service->getTodosCamionistas();
                menu.mostrarSucessoRegistarCamionista(camionistas);
            }
            catch(std::invalid_argument &e){
                menu.mostrarErro(e.what());
            }
        }
        else if(opcao == 5){
            std::vector<CamiaoDTO> camioes = service->getTodosCamioes();
            std::string matricula = menu.pedirSelecaoCamiao(camioes);
            
            bool confirmacao = menu.pedirConfirmacao();
            if(confirmacao){
                try{
                    service->removerCamiao(matricula);
                    std::vector<CamiaoDTO> camoesAtualizados = service->getTodosCamioes();
                    menu.mostrarSucessoRemoverCamiao(camoesAtualizados);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            } else {
                menu.mostrarErro("Acao cancelada.");
            }
        }
    }
}