#include "..\..\Headers\View\MenuPrincipal.h"
#include "..\..\Headers\View\MenuGestor.h"
#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>
#include <limits>

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

        // Se o input nao for um numero (ex: uma letra), o cin entra em
        // estado de erro. Limpamos o erro e descartamos o input invalido
        // para evitar que o programa feche ou entre em loop infinito
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcao invalida.\n";
            continue;
        }

        if(opcao >= 0 && opcao <= 2)
            return opcao; // devolve diretamente
        else
            cout << "Opcao invalida.\n";
    }
}
