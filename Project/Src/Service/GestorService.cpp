#include "..\..\Headers\Service\GestorService.h"
#include "..\..\Headers\Model\CamiaoDTO.h"
#include "..\..\Headers\Model\CamionistaDTO.h"
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

void GestorService::registrarCamionista(std::string nomeCamionista){
    if(camionistaContainer->validarNome(nomeCamionista) != nullptr){//ja existe
        throw std::invalid_argument("Camionista já existente");
    }
    Camionista camionista(nomeCamionista);
    camionistaContainer->guardar(camionista);
}

std::vector<CamiaoDTO> GestorService::getTodosCamioes(){
    std::vector<Camiao>& camioes = camiaoContainer->getTodos();
    //& porque senao faziamos copia e gasta memoria desnecessaria
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

std::vector<CamionistaDTO> GestorService::getTodosCamionistas(){
    std::vector<Camionista>& camionistas = camionistaContainer->getTodos();
    std::vector<CamionistaDTO> dtos;

    for(int i = 0; i < camionistas.size(); i++){
        CamionistaDTO dto;
        dto.nome = camionistas[i].getNome();
        dto.estado = camionistas[i].getEstado();
        dtos.push_back(dto);
    }
    return dtos;
}