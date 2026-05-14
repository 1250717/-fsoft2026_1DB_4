#include "..\..\Headers\Model\Carga.h"

Carga::Carga(float peso, Localidade *destino) {
    this->peso = peso;
    this->estado = "Disponivel";
    this->destino = destino;
}

std::string Carga::getEstado() {
    return this->estado;
}

float Carga::getPeso() {
    return this->peso;
}

Localidade* Carga::getDestino() {
    return this->destino;
}

void Carga::setEstado(std::string estado) {
    this->estado = estado;
}