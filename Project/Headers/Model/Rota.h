#ifndef ROTA_H
#define ROTA_H

#include <string>
#include <vector>
#include "Carga.h"

class Rota {
private:
    int idRota;
    float distanciaTotal;
    std::string nomeCamionista;
    std::string matriculaCamiao;
    std::vector<Carga> cargas;

public:
    Rota(int id, std::string nomeCamionista, std::string matriculaCamiao, float distanciaTotal, std::vector<Carga> cargas);
    int getIdRota();
    std::string getNomeCamionista();
    std::string getMatriculaCamiao();
    float getDistanciaTotal();
    std::vector<Carga>& getCargas();
};

#endif