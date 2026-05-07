#include "Project\Headers\Model\CamiaoContainer.h"

Camiao* CamiaoContainer::validarMatricula(std::string matricula) {
    for (int i = 0; i < (int)camioes.size(); i++) {
        if (camioes[i].getMatricula() == matricula) {
            return &camioes[i];
        }
    }
    return nullptr;
}

void CamiaoContainer::guardar(Camiao camiao) {
    camioes.push_back(camiao);
}

std::vector<Camiao>& CamiaoContainer::getTodos() {
    return camioes;
}

std::vector<Camiao*> CamiaoContainer::getDisponiveis() {
    std::vector<Camiao*> disponiveis;
    for (int i = 0; i < (int)camioes.size(); i++) {
        if (camioes[i].getEstado() == "Disponivel") {
            disponiveis.push_back(&camioes[i]);
        }
    }
    return disponiveis;
}

Camiao* CamiaoContainer::procurar(std::string matricula) {
    for (int i = 0; i < (int)camioes.size(); i++) {
        if (camioes[i].getMatricula() == matricula) {
            return &camioes[i];
        }
    }
    return nullptr;
}

void CamiaoContainer::remover(std::string matricula) {
    for (int i = 0; i < (int)camioes.size(); i++) {
        if (camioes[i].getMatricula() == matricula) {
            camioes.erase(camioes.begin() + i);
            return;
        }
    }
}