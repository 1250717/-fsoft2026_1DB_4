#include "..\..\Headers\Model\Carga.h"

Carga::Carga(float peso, Localidade *destino) {
    verificarPeso(peso); // garante que nao é criado em nenhum lado com condicoes erradas
    // O controller já chama Carga::verificarPeso() antes de criar a Carga,
// mas validar aqui também garante que nenhum outro código no futuro
// consiga criar uma Carga com peso inválido — defesa em profundidade.
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
    if(peso < 5 || peso > 200){
        throw std::invalid_argument("O peso da carga deve ser estar entre 5kg a 200kg.");
    }
}