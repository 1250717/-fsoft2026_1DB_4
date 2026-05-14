#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>

MenuCamionista::MenuCamionista(CamionistaController *controller){
    this->controller = controller;
}

bool MenuCamionista::login() {
    std::cout << "Nome do camionista: ";
    std::string nome;
    std::cin >> nome;
    this->nomeCamionista = nome;
    
    if(controller->verificarLogin(nome)) {
        std::cout << "Login com sucesso!\n";
        return true;
    } else {
        std::cout << "Camionista não encontrado!\n";
        return false;
    }
}

void MenuCamionista::mostrar(){
    if(!login()){ //login corre na mesma
        return;
    }
    
    while(true){
        std::cout << "1. Visualizar estado do camião\n";
        std::cout << "2. Adicionar carga\n";
        std::cout << "3. Remover carga\n";
        std::cout << "4. Iniciar entrega\n";
        std::cout << "0. Logout\n";
        
        std::cout << "Escolha uma opção: \n";
        int opcao;
        std::cin >> opcao;
        
        if(opcao == 0){
            break;
        }

        else if(opcao == 1){
            CamiaoDTO dto = controller->visualizarEstadoCamiao(nomeCamionista);
// chama o service que vai ao container, encontra o camionista, acede ao camiao e preenche o DTO
            std::cout << "Capacidade máxima: " << dto.capacidadeMaxima << "\n";
            std::cout << "Capacidade disponível: " << dto.capacidadeDisponivel << "\n";
            std::cout << "Cargas atribuídas:\n";
            for(int i = 0; i < dto.cargas.size(); i++){
                std::cout << i+1 << ". " << dto.cargas[i] << "\n";
            }
        }
    }
}