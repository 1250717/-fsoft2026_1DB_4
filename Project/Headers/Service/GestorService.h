#ifndef GESTORSERVICE_H
#define GESTORSERVICE_H

#include <string>
#include "Project\Headers\Model\CamiaoContainer.h"
#include "Project\Headers\Model\CamionistaContainer.h"
#include "Project\Headers\Model\CargaContainer.h"
#include "Project\Headers\Model\RotaContainer.h"

class GestorService {
private:
    CamiaoContainer *camiaoContainer;
    CamionistaContainer *camionistaContainer;
    CargaContainer *cargaContainer;
    RotaContainer *rotaContainer;
    
public:
    GestorService(CamiaoContainer *camiaoContainer, CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer);

    
};

#endif