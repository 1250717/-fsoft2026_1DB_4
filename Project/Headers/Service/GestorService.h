#ifndef GESTORSERVICE_H
#define GESTORSERVICE_H

#include <string>
#include "..\Model\CamiaoContainer.h"
#include "..\Model\CamionistaContainer.h"
#include "..\Model\CargaContainer.h"
#include "..\Model\RotaContainer.h"
#include <vector>
#include "..\Model\CamiaoDTO.h"
#include "..\Model\CamionistaDTO.h"

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

    void registrarCamionista(std::string nomeCamionista);

    std::vector<CamiaoDTO> getTodosCamioes();

    std::vector<CamionistaDTO> getTodosCamionistas();
};

#endif