#include "Project\Headers\Service\GestorService.h"
#include <iostream>


GestorService::GestorService(CamiaoContainer *camiaoContainer, CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer) {
    this->camiaoContainer = camiaoContainer;
    this->camionistaContainer = camionistaContainer;
    this->cargaContainer = cargaContainer;
    this->rotaContainer = rotaContainer;
}
