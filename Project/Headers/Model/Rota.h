#ifndef ROTA_H
#define ROTA_H

#include <string>
#include <vector>

class Rota {
private:
    int idRota;
    float distanciaTotal;
    std::string nomeCamionista;
    std::string matriculaCamiao;
    std::vector<std::string> destinos; // so nomes dos destinos — nao precisamos das Carga completas

public:
    Rota(int id, std::string nomeCamionista, std::string matriculaCamiao, float distanciaTotal, std::vector<std::string> destinos);
    int getIdRota();
    std::string getNomeCamionista();
    std::string getMatriculaCamiao();
    float getDistanciaTotal();
    std::vector<std::string>& getDestinos();
};

#endif