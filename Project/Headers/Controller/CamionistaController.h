#ifndef CAMIONISTACONTROLLER_H
#define CAMIONISTACONTROLLER_H

#include "..\Service\CamionistaService.h"
#include "..\Model\CamiaoDTO.h"
#include <string>

class CamionistaController{
private:
    CamionistaService *service;
public:
    CamionistaController(CamionistaService *service);
    bool verificarLogin(std::string nome);

    CamiaoDTO visualizarEstadoCamiao(std::string nomeCamionista);

    
};

#endif