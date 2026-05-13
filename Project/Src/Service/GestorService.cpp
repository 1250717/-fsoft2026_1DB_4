

//NAO É SUPOSTO IMPRIMIR COISAS NO SERVICE
// ISSO É O PAPEL DO VIEW
// BRUNO É PARA TI ISTO MANO
//É SUPOSTO USAR EMPRESA GETS




#include "Project\Headers\Service\GestorService.h"
#include <iostream>

using namespace std;

GestorService::GestorService(CamiaoContainer *camiaoContainer, CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer) {
    this->camiaoContainer = camiaoContainer;
    this->camionistaContainer = camionistaContainer;
    this->cargaContainer = cargaContainer;
    this->rotaContainer = rotaContainer;
}
