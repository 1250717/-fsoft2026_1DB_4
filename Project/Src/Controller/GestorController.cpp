#include "..\..\Headers\Controller\GestorController.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CamionistaDTO.h"
#include <iostream>

GestorController::GestorController(GestorService *service){
    this->service = service;
}

void GestorController::mostrarMenu(){
    //quero chamar o menuGestor
    //para guardar o nome do gestor atual
    //nao vamos ter login
    //mas quero guardar o nome do gestor
    //ou seja chamamos o menu que criamos no .h
    //MenuGestor menu
    nomeGestor = menu.pedirNomeGestor();
    while(true){
        int opcao = menu.mostrarOpcoes();

        if(opcao == 0){
            break; // queremos sair do loop
            //do menu Gestor
            //podemos querer entrar como camionista
            //com o break saimos deste loop
            //mas continuamos no loop
            //do menuPrincipal Controller
        }
        else if(opcao == 1){//Registar Camiao
            //Gestor insere a matrícula do camião
            std::string matricula = menu.pedirMatricula();
            //Gestor insere a capacidade máxima do camião
            float capacidadeMaxima = menu.pedirCapacidadeMaxima();
            try{//try diz executa isto e fica atento a erros
                service->registrarCamiao(matricula, capacidadeMaxima);
                //se a matricula ja existe ele faz throw
                //interrompe a função imediatamente 
                //e envia um erro para quem a chamou.
                
                std::vector<CamiaoDTO> camioes = service->getTodosCamioes();
                menu.mostrarSucessoRegistarCamiao(camioes);
            }
            catch(std::invalid_argument &e) {
                //chamamos ao objeto que o throw
                //criou de e
                //mas podia ser erro por exemplo
                menu.mostrarErro(e.what());  // controller delega a impressão ao menu
                //what devolve a mensagem
                //que metemos no throw
            }
        }
        else if(opcao == 2){//registar Camionista
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
    }

}