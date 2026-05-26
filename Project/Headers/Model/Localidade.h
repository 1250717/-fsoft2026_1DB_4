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
    std::string getNome();
    float calcularDistancia(Localidade& outra);
    
    float getCoordenadaX();
    float getCoordenadaY();
};

#endif