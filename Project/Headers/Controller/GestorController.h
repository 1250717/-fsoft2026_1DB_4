#ifndef GESTORCONTROLLER_H
#define GESTORCONTROLLER_H

#include "Project\Headers\Model\CamiaoContainer.h"
#include "Project\Headers\Model\CamionistaContainer.h"
#include "Project\Headers\Model\CargaContainer.h"
#include "Project\Headers\Model\RotaContainer.h"
#include "Project\Headers\Service\GestorService.h"
#include <string>

class GestorController {
private:
    CamiaoContainer *camiaoContainer;
    CamionistaContainer *camionistaContainer;
    CargaContainer *cargaContainer;
    RotaContainer *rotaContainer;
    GestorService *service;

public:
    GestorController(CamiaoContainer *camiaoContainer, CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer, GestorService *service);

    bool registarCamiao (std::string matricula, std::string capacidade);
    bool registarCamionista (std::string nome);
    bool registarCarga (float pesa, std::string destino);
    bool atribuitCamionista (std::string matricula, std::string nome);
    bool removerCamionista (std::string nome);
    bool removerCamiao (std::string matricula, std::string capacidade);
    bool removerCarda (float peso, std::string destino);
};

#endif