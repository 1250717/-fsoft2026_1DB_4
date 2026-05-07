#ifndef CAMIONISTACONTAINER_H
#define CAMIONISTACONTAINER_H

#include <vector>
#include <string>
#include "Camionista.h"

class CamionistaContainer{
private:
    std::vector<Camionista> camionistas;

public:
    void guardar(Camionista camionista);
    Camionista* procurar(std::string nome);
};
#endif