#include "..\..\Headers\Model\Rota.h"

Rota::Rota(int id, std::string nomeCamionista, std::string matriculaCamiao, float distanciaTotal, std::vector<Carga> cargas) {
    this->idRota = id;
    this->nomeCamionista = nomeCamionista;
    this->matriculaCamiao = matriculaCamiao;
    this->distanciaTotal = distanciaTotal;
    this->cargas = cargas; // Como agora ambos são vectores, podes atribuir diretamente
}

int Rota::getIdRota() {
    return this->idRota;
}

std::string Rota::getNomeCamionista() {
    return this->nomeCamionista;
}

std::string Rota::getMatriculaCamiao() {
    return this->matriculaCamiao;
}

float Rota::getDistanciaTotal() {
    return this->distanciaTotal;
}

std::vector<Carga>& Rota::getCargas() {
    return this->cargas;
}