#include "Project\Headers\Model\CargaContainer.h"

void CargaContainer::guardar(Carga carga) {
    cargas.push_back(carga);
}

std::vector<Carga>& CargaContainer::getTodos() {
    return cargas;
}

Carga* CargaContainer::procurar(int indice) {
    if (indice < 0 || indice >= (int)cargas.size()) {
        return nullptr;
    }
    return &cargas[indice];
}

void CargaContainer::remover(int indice) {
    if (indice < 0 || indice >= (int)cargas.size()) {
        return;
    }
    cargas.erase(cargas.begin() + indice);
}

std::vector<Carga*> CargaContainer::getDisponiveis() {
    std::vector<Carga*> disponiveis;
    for (int i = 0; i < (int)cargas.size(); i++) {
        if (cargas[i].getEstado() == "Disponivel") {
            disponiveis.push_back(&cargas[i]);
        }
    }
    return disponiveis;
}