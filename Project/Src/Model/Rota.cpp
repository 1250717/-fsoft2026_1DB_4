#include "..\..\Headers\Model\Rota.h"

Rota::Rota(int id, std::string nomeCamionista, std::string matriculaCamiao, float distanciaTotal, std::vector<std::string> destinos) {
    this->idRota = id;
    this->nomeCamionista = nomeCamionista;
    this->matriculaCamiao = matriculaCamiao;
    this->distanciaTotal = distanciaTotal;
    this->destinos = destinos;
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

std::vector<std::string>& Rota::getDestinos() {
    return this->destinos;
}