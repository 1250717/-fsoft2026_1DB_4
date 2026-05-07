#pragma once
#include <list>
#include "Rota.h" 

class RotaContainer {
private:
    
    std::list<Rota> rotas; 

public:
    
    void guardar(Rota rota); 
    
    std::list<Rota>& getTodos(); 
};
