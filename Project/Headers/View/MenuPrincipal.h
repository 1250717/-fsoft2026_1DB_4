#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "Project\Headers\Controller\CamionistaController.h"

class MenuPrincipal {
private:
    CamionistaController *camionistaController;

public:
    MenuPrincipal(CamionistaController &camionistaController);
    void mostrar();
};

#endif