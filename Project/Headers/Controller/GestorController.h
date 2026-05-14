#ifndef GESTORCONTROLLER_H
#define GESTORCONTROLLER_H

#include "Project\Headers\Service\GestorService.h"
#include "Project\Headers\View\MenuGestor.h"

class GestorController {
private:
    GestorService *service;
    MenuGestor *view;

public:
    GestorController(GestorService *service, MenuGestor *view);

    void iniciar();
    bool registarCamiao (std::string matricula, std::string capacidade);
    bool registarCamionista (std::string nome);
    bool registarCarga (float pesa, std::string destino);
    bool atribuitCamionista (std::string matricula, std::string nome);
    bool removerCamionista (std::string nome);
    bool removerCamiao (std::string matricula, std::string capacidade);
    bool removerCarda (float peso, std::string destino);
};



#endif