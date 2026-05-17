#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "CamiaoContainer.h"
#include "CamionistaContainer.h"
#include "CargaContainer.h"
#include "RotaContainer.h"
#include "LocalidadeContainer.h"

class Empresa {
private:
    std::string nif;
    std::string nome;
    float coordenadaX;
    float coordenadaY;
    CamiaoContainer camiaoContainer;
    CamionistaContainer camionistaContainer;
    CargaContainer cargaContainer;
    RotaContainer rotaContainer;
    LocalidadeContainer localidadeContainer;

public:
    Empresa(std::string nif, std::string nome);
    float getCoordenadaX();
    float getCoordenadaY();
    CamiaoContainer& getCamiaoContainer();
    CamionistaContainer& getCamionistaContainer();
    CargaContainer& getCargaContainer();
    RotaContainer& getRotaContainer();
    LocalidadeContainer& getLocalidadeContainer();
};

#endif