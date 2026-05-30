#ifndef CARGA_H
#define CARGA_H

#include <string>
#include "Localidade.h"
#include <stdexcept>


class Carga {
private:
    float peso;
    std::string estado;
    Localidade *destino;

public:
    Carga(float peso,Localidade *destino);
    std::string getEstado();
    float getPeso();

    void static verificarPeso(float peso);

    Localidade* getDestino();
    void setEstado(std::string estado);
};

#endif