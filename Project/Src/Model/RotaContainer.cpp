#include "..\..\Headers\Model\RotaContainer.h"

std::vector<Rota>& RotaContainer::getTodos(){
    return this->rotas;
}

void RotaContainer::guardar(Rota rota){
    rotas.push_back(rota);
}