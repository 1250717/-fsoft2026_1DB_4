#ifndef GESTORCONTROLLER_H
#define GESTORCONTROLLER_H

#include "..\Service\GestorService.h"
#include "..\View\MenuGestor.h"

class GestorController {
private:
    GestorService *service;
    MenuGestor menu; //criamos aqui, porque o controller é que chama o menu, depois recebe informacao
    //e toma uma decisao
    std::string nomeGestor;

public:
    GestorController(GestorService *service);
    void mostrarMenu();
};



#endif
