#ifndef GESTORSERVICE_H
#define GESTORSERVICE_H

#include <string>
#include <vector>
#include "..\Model\CamiaoContainer.h"
#include "..\Model\CamionistaContainer.h"
#include "..\Model\CargaContainer.h"
#include "..\Model\RotaContainer.h"
#include "..\Dtos\CamiaoDTO.h"
#include "..\Dtos\CamionistaDTO.h"
#include "..\Dtos\CargaDTO.h"

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

    void registarCarga(float peso);

    std::vector<CamiaoDTO> getTodosCamioes();

    std::vector<CamionistaDTO> getTodosCamionistas();

    std::vector<CargaDTO>getTodasCargas();
};

#endif