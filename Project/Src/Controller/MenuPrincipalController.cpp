#include "..\..\Headers\Controller\MenuPrincipalController.h"
#include "..\..\Headers\Controller\CamionistaController.h"

MenuPrincipalController::MenuPrincipalController(CamionistaService *service) {
    this->camionistaService = service;
}

void MenuPrincipalController::mostrarMenu() {
    int opcao = menu.mostrar();

    if(opcao == 1) {
        // GestorController gestorController(gestorService);
        // gestorController.mostrarMenu();
    }
    else if(opcao == 2) {
        CamionistaController camionistaController(camionistaService);
        camionistaController.mostrarMenu();// falta implementar
    }
    else if(opcao == 0) {
        return;
    }
}