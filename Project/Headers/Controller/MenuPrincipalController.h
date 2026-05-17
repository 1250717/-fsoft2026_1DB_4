#ifndef MENUPRINCIPALCONTROLLER_H
#define MENUPRINCIPALCONTROLLER_H

#include "..\View\MenuPrincipal.h"
#include "..\Service\CamionistaService.h"
#include "..\Service\GestorService.h"

class MenuPrincipalController {
private:
    MenuPrincipal menu;
    CamionistaService *camionistaService;
    GestorService *gestorService; //precisamos de guardar ambos

public:
    MenuPrincipalController(CamionistaService *service, GestorService *service2);
    void mostrarMenu();// main chama isto
    //por sua vez chama o menu do main
    // menu principal mostra opcoes para escolher entre camionista ou gestor
    //o utilizador introduz o numero correspondente à opcao e a funcao MenuPrincipal mostrar devolve isso ao menuPrincipalController
    //que agora decide oque fazer com essa opcao
    //se o numero introduzido for 2
    // Cria o controller do camionista e mostra o menu do camionista
}; 

#endif