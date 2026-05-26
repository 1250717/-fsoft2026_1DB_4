#ifndef GESTORSERVICE_H
#define GESTORSERVICE_H

#include <string>
#include <vector>
#include "..\Model\CamiaoContainer.h"
#include "..\Model\CamionistaContainer.h"
#include "..\Model\CargaContainer.h"
#include "..\Model\RotaContainer.h"
#include "..\Model\LocalidadeContainer.h"
#include "..\Dtos\CamiaoDTO.h"
#include "..\Dtos\CamionistaDTO.h"
#include "..\Dtos\CargaDTO.h"

class GestorService {
private:
    CamionistaContainer *camionistaContainer;
    CamiaoContainer *camiaoContainer;
    CargaContainer *cargaContainer;
    RotaContainer *rotaContainer;
    LocalidadeContainer *localidadeContainer;
    
public:
    GestorService(CamionistaContainer *camionistaContainer, CamiaoContainer *camiaoContainer, 
        CargaContainer *cargaContainer, RotaContainer *rotaContainer, LocalidadeContainer *localidadeContainer);

    void registrarCamiao(std::string matricula, float capacidade);

    void registrarCamionista(std::string nomeCamionista);
    
    void removerCamiao(std::string matricula);

    void removerCamionista(std::string nomeCamionista);

    void registarCarga(float peso, std::string nomeDestino);

    std::vector<CamiaoDTO> getTodosCamioes();

    std::vector<CamionistaDTO> getTodosCamionistas();

    std::vector<CargaDTO>getTodasCargas();

    std::vector<Localidade>getTodasLocalidades();

 std::vector<CamionistaDTO> getCamionistasDisponiveis();

    std::vector<CamiaoDTO> getCamioesDisponiveis();
    
    void atribuirCamionistaACamiao(std::string nomeCamionista, std::string matricula);
    
};

#endif