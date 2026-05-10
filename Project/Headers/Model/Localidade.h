#ifndef LOCALIDADE_H
#define LOCALIDADE_H

#include <string>

class Localidade {
private:
    std::string nome;
    float coordenadaX;
    float coordenadaY;

public:
    Localidade(std::string nome, float coordenadaX, float coordenadaY);
    float calcularDistancia(Localidade& outra);
};

#endif