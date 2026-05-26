    #include "..\..\Headers\Controller\MenuPrincipalController.h"
    #include "..\..\Headers\Controller\CamionistaController.h"
    #include "..\..\Headers\Controller\GestorController.h"

    MenuPrincipalController::MenuPrincipalController(CamionistaService *service, GestorService *service2) {
        this->camionistaService = service;
        this->gestorService = service2;
    }

    void MenuPrincipalController::mostrarMenu() {
        while(true) {
            int opcao = menu.mostrar();

            if(opcao == 1) {
                GestorController gestorController(gestorService);
                gestorController.mostrarMenu();
            }
            else if(opcao == 2) {
                CamionistaController camionistaController(camionistaService);
                camionistaController.mostrarMenu();
            }
            else if(opcao == 0) {
                return;
            }
        }
    }