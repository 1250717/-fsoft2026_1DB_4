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
                    std::vector<CargaDTO> disponiveis = service->getCargasDisponiveis();
                    
                    if(disponiveis.empty()){
                        menu.mostrarErro("Nao existem cargas disponiveis.");
                        continue;
                    }
                    
                    menu.mostrarCargasDisponiveis(disponiveis);
                    int indice = menu.pedirIndiceCarga();
                    
                    service->adicionarCarga(nome, indice);
                    CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                    menu.mostrarSucessoAdicionarCarga(camiao);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }
            
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
                    
                    std::cout << "Confirma a remocao? (s/n): ";
                    std::string resposta;
                    std::cin >> resposta;
                    
                    if(resposta != "s" && resposta != "S"){
                        menu.mostrarErro("Operacao cancelada.");
                        continue;
                    }
                    
                    service->removerCarga(nome, indice);
                    CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                    menu.mostrarSucessoAdicionarCarga(camiao);
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
                    
                    std::cout << "Confirma o inicio da entrega? (s/n): ";
                    std::string resposta;
                    std::cin >> resposta;
                    
                    if(resposta != "s" && resposta != "S"){
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