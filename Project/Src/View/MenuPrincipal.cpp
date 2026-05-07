#include "Project\Headers\View\MenuPrincipal.h"
#include "Project\Headers\View\MenuGestor.h"
#include "Project\Headers\View\MenuCamionista.h"
#include <iostream>

using namespace std;

void MenuPrincipal::mostrar() {
    CamionistaContainer container;
    CamionistaService service(&container);
    CamionistaController controller(&service);

    while(true) {
        cout << "Introduza opção: \n";
        cout << "1. Gestor\n";
        cout << "2. Camionista\n";
        cout << "0. Sair\n";
        
        int opcao;
        cin >> opcao;
        
        if(opcao == 1) {
            MenuGestor menuGestor;
            menuGestor.mostrar();
        }
        else if(opcao == 2) {
            MenuCamionista menuCamionista(&controller);
            menuCamionista.mostrar();
        }
        else if(opcao == 0) {
            break;
        }
        else{
            printf("Opção inválida.");
        }
    }
}