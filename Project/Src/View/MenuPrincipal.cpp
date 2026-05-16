#include "..\..\Headers\View\MenuPrincipal.h"
#include "..\..\Headers\View\MenuGestor.h"
#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>

using namespace std;

int MenuPrincipal::mostrar() {
    int opcao;
    while(true) {
        cout << "Introduza opcao:\n";
        cout << "1. Gestor\n";
        cout << "2. Camionista\n";
        cout << "0. Sair\n";
        cin >> opcao;

        if(opcao >= 0 && opcao <= 2)
            return opcao; // devolve diretamente
        else
            cout << "Opcao invalida.\n";
    }
}