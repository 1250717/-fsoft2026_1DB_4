#include "..\..\Headers\Controller\GestorController.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CamionistaDTO.h"
#include "..\..\Headers\Dtos\RotaDTO.h"
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
        // UC 9.1 - Registar Camiao
        else if(opcao == 1){
            std::string matricula;
            while(true){
                matricula = menu.pedirMatricula();
                if(matricula == "v") break;
                try{
                    Camiao::validarMatricula(matricula);
                    break;
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }
            if(matricula == "v") continue;

            float capacidadeMaxima;
            while(true){
                capacidadeMaxima = menu.pedirCapacidadeMaxima();
                try{
                    Camiao::validarCapacidade(capacidadeMaxima);
                    break;
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }

            try{
                service->registrarCamiao(matricula, capacidadeMaxima);
                std::vector<CamiaoDTO> camioes = service->getTodosCamioes();
                menu.mostrarSucessoRegistarCamiao(camioes);
            }
            catch(std::invalid_argument &e){
                menu.mostrarErro(e.what());
            }
        }
        // UC 9.2 - Registar Camionista
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
        // UC 9.3 - Registar Carga
        else if(opcao == 3){
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
        // UC 9.4 - Atribuir Camionista a Camiao
        else if(opcao == 4){
            std::vector<CamionistaDTO> camionistasDisp = service->getCamionistasDisponiveis();

            if(camionistasDisp.empty()){
                menu.mostrarErro("Nao existem camionistas disponiveis.");
                continue;
            }

            menu.mostrarCamionistasDisponiveis(camionistasDisp);
            std::string nomeCamionista = menu.pedirNomeCamionista();

            std::vector<CamiaoDTO> camioesDisp = service->getCamioesDisponiveis();

            if(camioesDisp.empty()){
                menu.mostrarErro("Nao existem camioes disponiveis.");
                continue;
            }

            menu.mostrarCamioesDisponiveis(camioesDisp);
            std::string matricula = menu.pedirMatricula();

            try{
                service->atribuirCamionistaACamiao(nomeCamionista, matricula);
                menu.mostrarSucessoAtribuicao(nomeCamionista, matricula);
            }
            catch(std::invalid_argument &e){
                menu.mostrarErro(e.what());
            }
        }
        // UC 9.5 - Remover Camiao
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
        // UC 9.6 - Remover Camionista
        else if(opcao == 6){
            std::vector<CamionistaDTO> camionistas = service->getTodosCamionistas();
            std::string nomeCamionista = menu.pedirSelecaoCamionista(camionistas);

            bool confirmacao = menu.pedirConfirmacao();
            if(confirmacao){
                try{
                    service->removerCamionista(nomeCamionista);
                    std::vector<CamionistaDTO> camionistasAtualizados = service->getTodosCamionistas();
                    menu.mostrarSucessoRemoverCamionista(camionistasAtualizados);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            } else {
                menu.mostrarErro("Acao cancelada.");
            }
        }
        // UC 9.7 - Eliminar Carga
        else if(opcao == 7){
            std::vector<CargaDTO> cargas = service->getTodasCargas();
            int indice = menu.pedirSelecaoCarga(cargas);

            try{
                service->eliminarCarga(indice);
            }
            catch(std::invalid_argument &e){
                menu.mostrarErro(e.what());
                continue;
            }

            bool confirmacao = menu.pedirConfirmacao();

            if(confirmacao){
                try{
                    service->eliminarCarga(indice, true);
                    std::vector<CargaDTO> cargasAtualizadas = service->getTodasCargas();
                    menu.mostrarSucessoEliminarCarga(cargasAtualizadas);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            } else {
                menu.mostrarErro("Ação cancelada.");
            }
        }
        // UC 9.8 - Visualizar Cadastros
        else if(opcao == 8){
            std::vector<CamiaoDTO> camioes = service->getTodosCamioes();
            std::vector<CamionistaDTO> camionistas = service->getTodosCamionistas();
            menu.visualizarCadastros(camioes, camionistas);
        }
        // UC 9.9 - Visualizar Rotas Concluidas
        else if(opcao == 9){
            std::vector<RotaDTO> rotas = service->getTodasRotas();

            if(rotas.empty()){
                menu.mostrarErro("Nao existem rotas concluidas.");
                continue;
            }

            menu.mostrarRotasConcluidas(rotas);
        }
    }
}