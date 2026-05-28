#include "..\..\Headers\View\MenuPrincipal.h"
#include "..\..\Headers\View\MenuGestor.h"
#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>

using namespace std;

int MenuPrincipal::mostrar() {
    int opcao;
    while(true) {
        cout << "\n Introduza opcao:";
        cout << "\n 1 - Gestor";
        cout << "\n 2 - Camionista";
        cout << "\n 0 - Sair";
        cout << "\n Opcao: ";
        cin >> opcao;

        if(opcao >= 0 && opcao <= 2)
            return opcao; // devolve diretamente
        else
            cout << "Opcao invalida.\n";
    }
}



