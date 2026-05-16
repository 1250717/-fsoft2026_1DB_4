#include "..\..\Headers\Controller\GestorController.h"
#include <iostream>

void GestorController::iniciar(){
    int opcao;
    do{
        view->mostrar();
        switch (opcao){
            case 1: registarCamiao(std::string matricula, std::string capacidade); break;
            case 2: registarCamionista(); break;
            case 3: registarCarga(); break;
            case 4: atribuitCamionista(); break;
            case 5: removerCamiao(); break;
            case 6: removerCamionista(); break;
            case 7: removerCarga(); break;
            case 8: 
        }
    } while (opcao >= 0 && opcao < 9);
}