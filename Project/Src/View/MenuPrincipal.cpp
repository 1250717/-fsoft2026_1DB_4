#include "..\..\Headers\View\MenuPrincipal.h"
#include "..\..\Headers\View\MenuGestor.h"
#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>

using namespace std;

MenuPrincipal::MenuPrincipal(CamionistaController &camionistaController){
    this->camionistaController = &camionistaController;
}

void MenuPrincipal::mostrar() {

    while(true) {
        cout << "Introduza opcao: \n";
        cout << "1. Gestor\n";
        cout << "2. Camionista\n";
        cout << "0. Sair\n";
        
        int opcao;
        cin >> opcao;
        
        if(opcao == 1) {
            break;
        }
        else if(opcao == 2) {
            MenuCamionista menuCamionista(camionistaController);
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