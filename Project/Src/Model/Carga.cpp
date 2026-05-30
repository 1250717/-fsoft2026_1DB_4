#include "..\..\Headers\Model\Carga.h"

Carga::Carga(float peso, Localidade *destino) {
    verificarPeso(peso); // construtor valida — impossivel criar Carga com peso invalido
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

void Carga::verificarPeso(float peso){
    if(peso <= 0){
        throw std::invalid_argument("O peso da carga deve ser maior que 0.");
    }
}