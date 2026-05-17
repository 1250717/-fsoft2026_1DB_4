#ifndef ROTADTO_H
#define ROTADTO_H

#include <string>
#include <vector>

class RotaDTO {
public:
    int idRota;
    float distanciaTotal;
    std::string nomeCamionista;
    std::string matriculaCamiao;
    std::vector<std::string> destinosOrdemFIFO; // destinos na ordem de entrega // descrição simples de cada carga
};

#endif