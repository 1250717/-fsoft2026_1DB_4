#include "..\..\Headers\Service\GestorService.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CamionistaDTO.h"
#include "..\..\Headers\Mapper\CamiaoMapper.h"
#include "..\..\Headers\Mapper\CamionistaMapper.h"
#include "..\..\Headers\Mapper\RotaMapper.h"
#include "..\..\Headers\Dtos\RotaDTO.h"
#include <stdexcept>

GestorService::GestorService(CamionistaContainer *camionistaContainer, CamiaoContainer *camiaoContainer, 
        CargaContainer *cargaContainer, RotaContainer *rotaContainer){
    this->camiaoContainer = camiaoContainer;
    this->camionistaContainer = camionistaContainer;
    this->cargaContainer = cargaContainer;
    this->rotaContainer = rotaContainer;
}

void GestorService::registrarCamiao(std::string matricula, float capacidade){
    if(capacidade <= 0){
        throw std::invalid_argument("Capacidade tem de ser positiva.");
    }
    if(camiaoContainer->procurar(matricula) != nullptr) { 
        throw std::invalid_argument("Matricula ja existente.");
    }
    // se chegou aqui, a matrícula não existe
    Camiao camiao(matricula, capacidade);
    camiaoContainer->guardar(camiao);
}

void GestorService::registrarCamionista(std::string nomeCamionista){
    if(nomeCamionista.empty()){
        throw std::invalid_argument("Nome nao pode estar vazio.");
    }
    if(camionistaContainer->validarNome(nomeCamionista) != nullptr){//ja existe
        throw std::invalid_argument("Camionista já existente");
    }
    Camionista camionista(nomeCamionista);
    camionistaContainer->guardar(camionista);
}

std::vector<CamiaoDTO> GestorService::getTodosCamioes(){
    std::vector<Camiao>& camioes = camiaoContainer->getTodos();
    std::vector<CamiaoDTO> dtos;
    for(int i = 0; i < camioes.size(); i++){
        dtos.push_back(CamiaoMapper::toDTO(camioes[i]));
    }
    return dtos;
}

std::vector<CamionistaDTO> GestorService::getTodosCamionistas(){
    std::vector<Camionista>& camionistas = camionistaContainer->getTodos();
    std::vector<CamionistaDTO> dtos;
    for(int i = 0; i < camionistas.size(); i++){
        dtos.push_back(CamionistaMapper::toDTO(camionistas[i]));
    }
    return dtos;
}

//visulaizar rotas

std::vector<RotaDTO> GestorService::getTodasRotas(){
    std::vector<Rota>& rotas = rotaContainer->getTodos();
    std::vector<RotaDTO> dtos;
    for(int i = 0; i < rotas.size(); i++){
        dtos.push_back(RotaMapper::toDTO(rotas[i]));
    }
    return dtos;