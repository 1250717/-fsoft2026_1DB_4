#include "Project\Headers\View\MenuCamionista.h"
#include "Project\Headers\Model\CamionistaContainer.h"
#include <iostream>

MenuCamionista::MenuCamionista(CamionistaController *controller){
    this->controller = controller;
}

bool MenuCamionista::login() {
    std::cout << "Nome do camionista: ";
    std::string nome;
    std::cin >> nome;
    
    if(controller->verificarLogin(nome)) {
        std::cout << "Login com sucesso!\n";
        return true;
    } else {
        std::cout << "Camionista não encontrado!\n";
        return false;
    }
}
