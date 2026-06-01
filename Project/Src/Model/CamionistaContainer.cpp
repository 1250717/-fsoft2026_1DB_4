#include "..\..\Headers\Model\CamionistaContainer.h"

Camionista* CamionistaContainer::validarNome(std::string nome) {
    return procurar(nome);
}

void CamionistaContainer::guardar(Camionista camionista) {
    camionistas.push_back(camionista);
}

std::vector<Camionista>& CamionistaContainer::getTodos() {
    return camionistas;
}

std::vector<Camionista*> CamionistaContainer::getDisponiveis() {
    std::vector<Camionista*> disponiveis;
    for (int i = 0; i < (int)camionistas.size(); i++) {
        if (camionistas[i].getEstado() == "Disponivel") {
            disponiveis.push_back(&camionistas[i]);
        }
    }
    return disponiveis;
}

Camionista* CamionistaContainer::procurar(std::string nome) {
    for (int i = 0; i < (int)camionistas.size(); i++) {
        if (camionistas[i].getNome() == nome) {
            return &camionistas[i];
        }
    }
    return nullptr;
}

void CamionistaContainer::remover(std::string nome) {
    for (int i = 0; i < (int)camionistas.size(); i++) {
        if (camionistas[i].getNome() == nome) {
            camionistas.erase(camionistas.begin() + i);
            return;
        }
    }
}

