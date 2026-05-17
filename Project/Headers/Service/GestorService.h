#ifndef GESTORSERVICE_H
#define GESTORSERVICE_H

#include <string>
#include "..\Model\CamiaoContainer.h"
#include "..\Model\CamionistaContainer.h"
#include "..\Model\CargaContainer.h"
#include "..\Model\RotaContainer.h"

class GestorService {
private:
    CamionistaContainer *camionistaContainer;
    CamiaoContainer *camiaoContainer;
    CargaContainer *cargaContainer;
    RotaContainer *rotaContainer;
    
public:
    GestorService(CamionistaContainer *camionistaContainer, CamiaoContainer *camiaoContainer, 
        CargaContainer *cargaContainer, RotaContainer *rotaContainer);

    void registrarCamiao(std::string matricula, float capacidade);
    std::vector<CamiaoDTO> getTodosCamioes();
};

#endif