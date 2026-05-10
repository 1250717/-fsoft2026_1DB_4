#ifndef ROTACONTAINER_H
#define ROTACONTAINER_H

#include <vector>
#include "Rota.h"

class RotaContainer {
private:
    std::vector<Rota> rotas;

public:
    std::vector<Rota>& getTodos();
    void guardar(Rota rota);
};

#endif