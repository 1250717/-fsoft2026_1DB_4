#include "..\..\Headers\Service\GestorService.h"
#include "..\..\Headers\Model\CamiaoDTO.h"
#include <stdexcept>

GestorService::GestorService(CamionistaContainer *camionistaContainer, CamiaoContainer *camiaoContainer, 
        CargaContainer *cargaContainer, RotaContainer *rotaContainer){
    this->camiaoContainer = camiaoContainer;
    this->camionistaContainer = camionistaContainer;
    this->cargaContainer = cargaContainer;
    this->rotaContainer = rotaContainer;
}

void GestorService::registrarCamiao(std::string matricula, float capacidade){
    if(camiaoContainer->procurar(matricula) != nullptr) { 
        throw std::invalid_argument("Matricula ja existente.");
    }
    // se chegou aqui, a matrícula não existe
    Camiao camiao(matricula, capacidade);
    camiaoContainer->guardar(camiao);
}

std::vector<CamiaoDTO> GestorService::getTodosCamioes(){
    std::vector<Camiao>& camioes = camiaoContainer->getTodos();
    std::vector<CamiaoDTO> dtos;
    for(int i = 0; i < camioes.size(); i++){
        CamiaoDTO dto;
        dto.matricula = camioes[i].getMatricula();
        dto.capacidadeMaxima = camioes[i].getCapacidadeMaxima();
        dto.capacidadeDisponivel = camioes[i].getCapacidadeDisponivel();
        dto.estado = camioes[i].getEstado();
        dtos.push_back(dto);
    }
    return dtos;
}