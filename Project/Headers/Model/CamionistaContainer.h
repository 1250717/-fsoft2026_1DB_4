#ifndef CAMIONISTACONTAINER_H
#define CAMIONISTACONTAINER_H

#include <string>
#include <vector>
#include "Camionista.h"

class CamionistaContainer {
private:
    std::vector<Camionista> camionistas;

public:
    Camionista* validarNome(std::string nome);
    void guardar(Camionista camionista);
    std::vector<Camionista>& getTodos();
    std::vector<Camionista*> getDisponiveis();
    Camionista* procurar(std::string nome);
    void remover(std::string nome);
};

#endif