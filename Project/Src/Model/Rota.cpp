#include "..\..\Headers\Model\Rota.h"
#include "..\..\Headers\Model\Camionista.h"
#include "..\..\Headers\Model\Camiao.h"
#include <stdexcept>

Rota::Rota(int id, std::string nomeCamionista, std::string matriculaCamiao, float distanciaTotal, std::vector<std::string> destinos) {
    if(id <= 0){
        throw std::invalid_argument("Id da rota invalido.");
    }
    Camionista::validarNome(nomeCamionista);
    Camiao::validarMatricula(matriculaCamiao);
    if(distanciaTotal < 0){
        throw std::invalid_argument("Distancia total nao pode ser negativa.");
    }
    if(destinos.empty()){
        throw std::invalid_argument("A rota tem de ter pelo menos um destino.");
    }

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