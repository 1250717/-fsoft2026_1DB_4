#ifndef CARGADTO_H
#define CARGADTO_H

#include <string>

class CargaDTO {
public:
    int indice; 
    float peso;
    std::string estado;
    std::string nomeDestino; // nome da localidade destino
};

#endif