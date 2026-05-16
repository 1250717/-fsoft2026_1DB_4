#ifndef CAMIONISTACONTROLLER_H
#define CAMIONISTACONTROLLER_H

#include "..\Service\CamionistaService.h"
#include "..\Model\CamiaoDTO.h"
#include "..\View\MenuCamionista.h"
#include <string>

class CamionistaController{
private:
    CamionistaService *service;
    MenuCamionista menu;
public:
    CamionistaController(CamionistaService *service);
    bool verificarLogin(std::string nome);

    CamiaoDTO visualizarEstadoCamiao(std::string nomeCamionista);

    void mostrarMenu();

    
};

#endif