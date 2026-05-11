#ifndef GESTORCONTROLLER_H
#define GESTORCONTROLLER_H

#include "Project\Headers\Model\CamiaoContainer.h"
#include "Project\Headers\Model\CamionistaContainer.h"
#include "Project\Headers\Model\CargaContainer.h"
#include "Project\Headers\Model\RotaContainer.h"

class GestorController {
private:
    CamiaoContainer *camiaoContainer;
    CamionistaContainer *camionistaContainer;
    CargaContainer *cargaContainer;
    RotaContainer *rotaContainer;
public:
    GestorController(CamiaoContainer *camiaoContainer, CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer, RotaContainer *rotaContainer);

    void registarCamiao(string matricula, float capacidade);
    void registarCamionista(string nome);
    void registarCarga(float peso, string destino);
    void listarTodos();
    void atribuirCamionista(string matriculaCamiao, string nomeCamionista);
    void removerCamionista(string nome);
    void removerCarga(int indice);
    void removerCamiao(string matricula);
    void listarRotasConcluidas();
};

#endif