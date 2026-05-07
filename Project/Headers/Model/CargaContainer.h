#ifndef CARGACONTAINER_H
#define CARGACONTAINER_H

#include <list>
#include <vector>
#include "Carga.h"


class CargaContainer {
private:
    std::list<Carga> cargas; ///< Lista interna de todas as cargas registadas

public:
   
    CargaContainer() = default;

    void guardar(Carga carga);

    std::list<Carga>& getTodos();


    Carga* procurar(int indice);

    
    void remover(int indice);

    std::vector<Carga*> getDisponiveis();
};

#endif // CARGACONTAINER_H