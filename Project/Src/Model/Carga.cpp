#include "Project\Headers\Model\Carga.h"

Carga::Carga(float peso, std::string estado, Localidade *destino){
    this->peso = peso;
    this->estado = "Disponivel";
    this->destino = destino;
}

std::string Carga::getEstado(){
    return this->estado;
}