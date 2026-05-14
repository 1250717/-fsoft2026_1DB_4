#ifndef GESTORCONTROLLER_H
#define GESTORCONTROLLER_H

#include "..\Model\CamiaoContainer.h"
#include "..\Model\CamionistaContainer.h"
#include "..\Model\CargaContainer.h"
#include "..\Model\RotaContainer.h"
#include "..\Service\GestorService.h"
#include <string>

class GestorController {
private:

public:

    bool registarCamiao (std::string matricula, std::string capacidade);
    bool registarCamionista (std::string nome);
    bool registarCarga (float pesa, std::string destino);
    bool atribuitCamionista (std::string matricula, std::string nome);
    bool removerCamionista (std::string nome);
    bool removerCamiao (std::string matricula, std::string capacidade);
    bool removerCarda (float peso, std::string destino);
};

#endif