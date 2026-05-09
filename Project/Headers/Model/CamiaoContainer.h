#ifndef CARGACONTAINER_H
#define CARGACONTAINER_H

#include <vector>
#include "Carga.h"

class CargaContainer {
private:
    std::vector<Carga> cargas;

public:
    void guardar(Carga carga);
    std::vector<Carga>& getTodos();
    Carga* procurar(int indice);
    void remover(int indice);
    std::vector<Carga*> getDisponiveis();
};

#endif