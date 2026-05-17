#ifndef LOCALIDADECONTAINER_H
#define LOCALIDADECONTAINER_H

#include <vector>
#include <string>
#include "Localidade.h"

class LocalidadeContainer {
private:
    std::vector<Localidade> localidades;

public:
    void guardar(Localidade localidade);
    std::vector<Localidade>& getTodos();
    Localidade* procurar(std::string nome);
    void remover(std::string nome);
};

#endif