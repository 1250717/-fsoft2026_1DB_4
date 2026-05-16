#ifndef MENUPRINCIPALCONTROLLER_H
#define MENUPRINCIPALCONTROLLER_H

#include "..\View\MenuPrincipal.h"
#include "..\Service\CamionistaService.h"

class MenuPrincipalController {
private:
    MenuPrincipal menu;
    CamionistaService *camionistaService;
public:
    MenuPrincipalController(CamionistaService *service);
    void mostrarMenu();// main chama isto
    //por sua vez chama o menu do main
    // menu principal mostra opcoes para escolher entre camionista ou gestor
    //o utilizador introduz o numero correspondente à opcao e a funcao MenuPrincipal mostrar devolve isso ao menuPrincipalController
    //que agora decide oque fazer com essa opcao
    //se o numero introduzido for 2
    // Cria o controller do camionista e mostra o menu do camionista
}; 

#endif