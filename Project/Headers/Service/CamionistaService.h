#ifndef CAMIONISTASERVICE_H
#define CAMIONISTASERVICE_H

#include <string>
#include "..\Model\CamionistaContainer.h"
#include "..\Dtos\CamiaoDTO.h"
#include "..\Model\Camionista.h"
#include "..\Model\Camiao.h"

class CamionistaService{
private:
    CamionistaContainer *container;

public:
    CamionistaService(CamionistaContainer *container);

    bool verificarLogin(std::string nome);

    CamiaoDTO visualizarEstadoCamiao(std::string nomeCamionista);

};

#endif