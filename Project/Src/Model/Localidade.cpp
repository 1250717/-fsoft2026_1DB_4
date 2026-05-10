#include "Project\Headers\Model\Localidade.h"
#include <cmath>

Localidade::Localidade(std::string nome, float coordenadaX, float coordenadaY) {
    this->nome = nome;
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
}

float Localidade::calcularDistancia(Localidade& outra) {
    float difX = outra.coordenadaX - this->coordenadaX; //distancia X
    float difY = outra.coordenadaY - this->coordenadaY;// distancia Y
    return std::sqrt(difX * difX + difY * difY); //raiz quadrada da soma, distancia total
}