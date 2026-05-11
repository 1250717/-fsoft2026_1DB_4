#ifndef CAMIONISTASERVICE_H
#define CAMIONISTASERVICE_H

#include <string>
#include "Project\Headers\Model\CamionistaContainer.h"
#include "Project\Headers\Model\CamiaoDTO.h"
#include "Project\Headers\Model\Camionista.h"
#include "Project\Headers\Model\Camiao.h"

class CamionistaService{
private:
    CamionistaContainer *container;

public:
    CamionistaService(CamionistaContainer *container);

    bool verificarLogin(std::string nome);

    CamiaoDTO visualizarEstadoCamiao(std::string nomeCamionista);

};

#endif