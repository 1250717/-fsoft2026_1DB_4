#ifndef MENUGESTOR_H
#define MENUGESTOR_H

#include "..\..\Headers\Service\GestorService.h"

class MenuGestor{
private:
    GestorService *service;
public:
    MenuGestor(GestorService *service);

    void mostrar();
    int lerOpcao();
};


#endif