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
                    // Loop: se o indice for invalido, volta a mostrar a lista
                    while(true){
                        std::vector<CargaDTO> disponiveis = service->getCargasDisponiveis(nome);
                        
                        if(disponiveis.empty()){
                            menu.mostrarErro("Nao existem cargas disponiveis.");
                            break;
                        }
                        
                        menu.mostrarCargasDisponiveis(disponiveis);
                        int indice = menu.pedirIndiceCarga();
                        
                        // Validacao de input: o indice tem de corresponder a uma
                        // carga da lista mostrada, senao mostra "Indice invalido"
                        bool indiceValido = false;
                        for(int i = 0; i < disponiveis.size(); i++){
                            if(disponiveis[i].indice == indice){
                                indiceValido = true;
                                break;
                            }
                        }
                        
                        // Indice invalido: volta a mostrar a lista (continue do while)
                        if(!indiceValido){
                            menu.mostrarErro("Indice invalido.");
                            continue;
                        }
                        
                        service->adicionarCarga(nome, indice);
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
            // Remover Carga
            else if(opcao == 3){
                try{
                    std::vector<CargaDTO> cargasDoCamiao = service->getCargasDoCamiao(nome);

                    if(cargasDoCamiao.empty()){
                        menu.mostrarErro("O camiao nao tem cargas atribuidas.");
                        continue;
                    }

                    menu.mostrarCargasDisponiveis(cargasDoCamiao);
                    int indice = menu.pedirIndiceCarga();

                    bool confirmacao = menu.pedirConfirmacao();
                    if(!confirmacao){
                        menu.mostrarErro("Operacao cancelada.");
                        continue;
                    }

                    service->removerCarga(nome, indice);
                    CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                    menu.mostrarSucessoRemoverCarga(camiao);
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