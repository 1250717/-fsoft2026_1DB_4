#ifndef GENERALREPOSITORY_H
#define GENERALREPOSITORY_H

#include "..\Model\CamionistaContainer.h"
#include "..\Model\CamiaoContainer.h"
#include "..\Model\CargaContainer.h"
#include "..\Model\RotaContainer.h"
#include "..\Model\LocalidadeContainer.h"

class GeneralRepository {
private:
    CamionistaContainer *camionistaContainer;
    CamiaoContainer *camiaoContainer;
    CargaContainer *cargaContainer;
    RotaContainer *rotaContainer;
    LocalidadeContainer *localidadeContainer;

    void carregarLocalidades();
    void carregarCamioes();
    void carregarCamionistas();
    void carregarCargas();
    void carregarRotas();

public:
    GeneralRepository(
        CamionistaContainer *camionistaContainer,
        CamiaoContainer *camiaoContainer,
        CargaContainer *cargaContainer,
        RotaContainer *rotaContainer,
        LocalidadeContainer *localidadeContainer
    );

    void carregar();
    void guardar();
};

#endif