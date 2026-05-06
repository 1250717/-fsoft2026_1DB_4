#pragma once
#include <list>
// Como não há asterisco na lista, TEMOS de incluir o ficheiro!
class Rota;
#include "Rota.h" 

class RotaContainer {
private:
    // Exatamente como no UML: sem asterisco!
    std::list<Rota> rotas; 

public:
    // No UML está: + guardar(rota: Rota): void
    void guardar(Rota rota); 
    
    // No UML está: + getTodos(): list<Rota>&
    std::list<Rota>& getTodos(); 
};