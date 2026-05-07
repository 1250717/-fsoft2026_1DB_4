#ifndef CAMIONISTACONTROLLER_H
#define CAMIONISTACONTROLLER_H

#include "CamionistaService.h"

class CamionistaController{
private:
    CamionistaService *service;
public:
    CamionistaController(CamionistaService *service);
    bool verificarLogin(std::string nome);

    
};

#endif
