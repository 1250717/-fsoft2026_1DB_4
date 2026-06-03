#include "..\..\Headers\Controller\CamionistaController.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CargaDTO.h"
#include "..\..\Headers\Dtos\RotaDTO.h"
#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>
#include <vector>
#include <string>

CamionistaController::CamionistaController(CamionistaService *service) {
    this->service = service;
}

bool CamionistaController::verificarLogin(std::string nome) {
    return service->verificarLogin(nome);
}

CamiaoDTO CamionistaController::visualizarEstadoCamiao(std::string nomeCamionista){
    return service->visualizarEstadoCamiao(nomeCamionista);
}

void CamionistaController::mostrarMenu(){
    std::string nome = menu.pedirNome();
    
    if(service->verificarLogin(nome)){
        while(true){
            int opcao = menu.mostrarOpcoes();
            
            if(opcao == 0) break;
            
            // Visualizar estado do camiao
            else if(opcao == 1){
                try{
                    CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                    menu.mostrarEstadoCamiao(camiao);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }
            
            // Adicionar Carga
            else if(opcao == 2){
                try{
                    while(true){
                        std::vector<CargaDTO> disponiveis = service->getCargasDisponiveis(nome);
                        //têm o indice real dentro do container
                        
                        if(disponiveis.empty()){
                            menu.mostrarErro("Nao existem cargas disponiveis.");
                            break;
                        }
                        
                        // Alteramos a lista temporariamente APENAS para exibição visual consecutiva (1, 2, 3...)
                        std::vector<CargaDTO> listaVisual = disponiveis;
                        for(int i = 0; i < listaVisual.size(); i++){
                            listaVisual[i].indice = i + 1; // Força o índice visual a ser sempre 1, 2, 3...
                        }
                        
                        menu.mostrarCargasDisponiveis(listaVisual);
                        std::string input = menu.pedirIndiceCarga();
                        
                        if(input == "v" || input == "V") break;
                        
                        int escolhaUtilizador;
                        try{
                            escolhaUtilizador = std::stoi(input);
                        }
                        catch(...){
                            menu.mostrarErro("Indice invalido.");
                            continue;
                        }
                        
                        // MAPEAMENTO: Verifica se a escolha bate certo com a nossa sequência (1 até N)
                        bool indiceValido = false;
                        int indiceRealNoContainer = -1;
                        
                        if (escolhaUtilizador >= 1 && escolhaUtilizador <= (int)disponiveis.size()) {
                            // Se o utilizador escolheu '2', ele quer o elemento no índice [2 - 1] = [1] da lista filtrada
                            indiceRealNoContainer = disponiveis[escolhaUtilizador - 1].indice;
                            indiceValido = true;
                        }
                        
                        if(!indiceValido){
                            menu.mostrarErro("Indice invalido.");
                            continue;
                        }
                        
                        // Envia para o service o índice REAL que mapeámos
                        service->adicionarCarga(nome, indiceRealNoContainer);
                        CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                        menu.mostrarSucessoAdicionarCarga(camiao);
                        break;
                    }
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }
            
            // Remover Carga
            else if(opcao == 3){
                try{
                    // Loop: indice invalido ou cancelamento volta a mostrar a lista
                    while(true){
                        std::vector<CargaDTO> cargasDoCamiao = service->getCargasDoCamiao(nome);

                        if(cargasDoCamiao.empty()){
                            menu.mostrarErro("O camiao nao tem cargas atribuidas.");
                            break;
                        }

                        menu.mostrarCargasDoCamiao(cargasDoCamiao);
                        std::string input = menu.pedirIndiceCarga();

                        // Opcao de voltar atras com "v"
                        if(input == "v" || input == "V") break;

                        // Converter o input para numero. Se nao for numero,
                        // o stoi lanca excecao -> tratamos como indice invalido
                        int indice;
                        try{
                            indice = std::stoi(input);
                        }
                        catch(...){
                            menu.mostrarErro("Indice invalido.");
                            continue;
                        }

                        // Validacao de input: o indice tem de corresponder a uma
                        // carga da lista. Se invalido, volta a lista SEM confirmacao
                        bool indiceValido = false;
                        for(int i = 0; i < cargasDoCamiao.size(); i++){
                            if(cargasDoCamiao[i].indice == indice){
                                indiceValido = true;
                                break;
                            }
                        }

                        if(!indiceValido){
                            menu.mostrarErro("Indice invalido.");
                            continue;
                        }

                        // Indice valido - pedir confirmacao
                        bool confirmacao = menu.pedirConfirmacao();

                        // Se nao confirma, volta a mostrar a lista
                        if(!confirmacao){
                            continue;
                        }

                        // Confirmou - remover a carga
                        service->removerCarga(nome, indice);
                        CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                        menu.mostrarSucessoRemoverCarga(camiao);
                        break;
                    }
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }

            // Iniciar Entrega
            else if(opcao == 4){
                try{
                    RotaDTO rota = service->calcularRota(nome);
                    menu.mostrarItinerario(rota);

                    bool confirmacao = menu.pedirConfirmacao();
                    if(!confirmacao){
                        menu.mostrarErro("Operacao cancelada.");
                        continue;
                    }

                    service->iniciarEntrega(nome);
                    menu.mostrarSucessoIniciarEntrega();
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }
        }
    }
    else {
        menu.mostrarErro("Nao e permitido entrar sem estar registado no sistema.");
    }
}