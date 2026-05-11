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

    void registarCamiao(std::string matricula, float capacidade);
    void registarCamionista(std::string nome);
    void registarCarga(float peso, std::string destino);
    void listarTodos();
    bool atribuirCamionista(std::string matriculaCamiao, std::string nomeCamionista);
    void removerCamionista(std::string nome);
    void removerCarga(int indice);
    void removerCamiao(std::string matricula);
    void listarRotasConcluidas();
};

#endif