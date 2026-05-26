
#include "..\..\Headers\Controller\CamionistaController.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CargaDTO.h"
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
            
            else if(opcao == 1){ // visualizar estado camiao
                CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                menu.mostrarEstadoCamiao(camiao);
            }
            
            else if(opcao == 2){ // UC2 - Adicionar Carga
                std::vector<CargaDTO> disponiveis = service->getCargasDisponiveis();
                
                if(disponiveis.empty()){
                    menu.mostrarErro("Nao existem cargas disponiveis.");
                    continue;
                }
                
                menu.mostrarCargasDisponiveis(disponiveis);
                int indice = menu.pedirIndiceCarga();
                
                try{ // tenta adicionar, se der erro mostra mensagem
                    service->adicionarCarga(nome, indice);
                    CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                    menu.mostrarSucessoAdicionarCarga(camiao);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());// o e.what devolve a mensagem do erro
                }
            }
            
            else if(opcao == 3){ // UC3 - Remover Carga
                std::vector<CargaDTO> cargasDoCamiao = service->getCargasDoCamiao(nome);
                
                if(cargasDoCamiao.empty()){
                    menu.mostrarErro("O camiao nao tem cargas atribuidas.");
                    continue;
                }
                
                // mostra usando o mesmo método das disponíveis (já existe)
                menu.mostrarCargasDisponiveis(cargasDoCamiao);
                int indice = menu.pedirIndiceCarga();
                
                // confirmação inline (sem método extra no menu)
                std::cout << "Confirma a remocao? (s/n): ";
                std::string resposta;
                std::cin >> resposta;
                
                if(resposta != "s" && resposta != "S"){
                    menu.mostrarErro("Operacao cancelada.");
                    continue;
                }
                
                try{
                    service->removerCarga(nome, indice);
                    CamiaoDTO camiao = service->visualizarEstadoCamiao(nome);
                    // reutiliza o método de sucesso do adicionar (mostra estado atualizado)
                    menu.mostrarSucessoAdicionarCarga(camiao);
                }
                catch(std::invalid_argument &e){
                    menu.mostrarErro(e.what());
                }
            }
            
            else if(opcao == 4){ // UC4 - Iniciar Entrega
                try{
                    // Calcular rota (sem alterar estado)
                    RotaDTO rota = service->calcularRota(nome);
                    
                    // Mostrar itinerario ao utilizador
                    menu.mostrarItinerario(rota);
                    
                    // Pedir confirmacao
                    std::cout << "Confirma o inicio da entrega? (s/n): ";
                    std::string resposta;
                    std::cin >> resposta;
                    
                    if(resposta != "s" && resposta != "S"){
                        menu.mostrarErro("Operacao cancelada.");
                        continue;
                    }
                    
                    // Iniciar entrega (altera estado)
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
