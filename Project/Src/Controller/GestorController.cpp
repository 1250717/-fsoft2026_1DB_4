#include "..\..\Headers\Controller\GestorController.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CamionistaDTO.h"
#include "..\..\Headers\Dtos\CargaDTO.h"
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
        else if(opcao == 1){//Registar Camiao
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
        else if(opcao == 2){//Registar Camionista
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
        else if(opcao==3){//Registar Carga
            float peso = menu.pedirPesoCarga();
            std::vector<Localidade> localidades = service->getTodasLocalidades();
            std::string nomeDestino = menu.pedirDestinoCarga(localidades);

            try{
                service->registarCarga(peso, nomeDestino);
                std::vector<CargaDTO> cargas = service->getTodasCargas();
                menu.mostrarSucessoRegistarCarga(cargas);
            }
            catch(std::invalid_argument &e){
                menu.mostrarErro(e.what());
            }
        }
        else if(opcao == 5){//Remover Camião
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
        else if(opcao==8){//Visualizar Cadastros
            std::vector<CamiaoDTO> camioes = service->getTodosCamioes();
            std::vector<CamionistaDTO> camionistas = service->getTodosCamionistas();
            menu.visualizarCadastros(camioes, camionistas);
        }
    }
}