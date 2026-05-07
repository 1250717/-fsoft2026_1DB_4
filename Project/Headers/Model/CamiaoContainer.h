#ifndef CAMIAOCONTAINER_H
#define CAMIAOCONTAINER_H

#include <string>
#include <vector>
#include "Camiao.h"

class CamiaoContainer {
private:
    std::vector<Camiao> camioes;

public:
    Camiao* validarMatricula(std::string matricula);
    
    void guardar(Camiao camiao);
    
    std::vector<Camiao>& getTodos();
    
    std::vector<Camiao*> getDisponiveis();
    
    Camiao* procurar(std::string matricula);
    
    void remover(std::string matricula);
};

#endif