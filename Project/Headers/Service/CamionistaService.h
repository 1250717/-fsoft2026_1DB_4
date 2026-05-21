#ifndef CAMIONISTASERVICE_H
#define CAMIONISTASERVICE_H

#include <string>
#include "..\Model\CamionistaContainer.h"
#include "..\Dtos\CamiaoDTO.h"
#include "..\Model\Camionista.h"
#include "..\Model\Camiao.h"
#include "..\Dtos\CargaDTO.h"
#include "..\Model\CargaContainer.h"

class CamionistaService{
private:
    CamionistaContainer *camionistaContainer;
    CargaContainer *cargaContainer;

public:
    CamionistaService(CamionistaContainer *camionistaContainer, CargaContainer *cargaContainer);

    bool verificarLogin(std::string nome);

    CamiaoDTO visualizarEstadoCamiao(std::string nomeCamionista);
    
    std::vector<CargaDTO> getCargasDisponiveis();
    void adicionarCarga(std::string nomeCamionista, int indiceCarga);

    std::vector<CargaDTO> getCargasDoCamiao(std::string nomeCamionista);
    void removerCarga(std::string nomeCamionista, int indiceCarga);

};

#endif