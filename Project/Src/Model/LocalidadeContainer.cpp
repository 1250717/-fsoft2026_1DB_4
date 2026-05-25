#include "..\..\Headers\Model\LocalidadeContainer.h"

void LocalidadeContainer::guardar(Localidade localidade) {
    localidades.push_back(localidade);
}

std::vector<Localidade>& LocalidadeContainer::getTodos() {
    return localidades;
}

Localidade* LocalidadeContainer::procurar(std::string nome) {
    for (int i = 0; i < localidades.size(); i++) {
        if (localidades[i].getNome() == nome) {
            return &localidades[i];
        }
    }
    return nullptr;
}

void LocalidadeContainer::remover(std::string nome) {
    for (int i = 0; i < localidades.size(); i++) {
        if (localidades[i].getNome() == nome) {
            localidades.erase(localidades.begin() + i);
            return;
        }
    }
}