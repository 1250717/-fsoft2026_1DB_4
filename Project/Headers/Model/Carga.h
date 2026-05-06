#ifndef CARGA_H
#define CARGA_H

#include <string>
#include <list>
#include "Localidade.h"

class Carga{
private:
    float peso;
    std::string estado;

    Localidade *destino;

public:
    Carga(float peso, std::string estado, Localidade *destino);
    std::string getEstado();
};

#endif