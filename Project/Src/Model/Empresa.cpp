#include "Project\Headers\Model\Empresa.h"

Empresa::Empresa(std::string nif, std::string nome) {
    this->nif = nif;
    this->nome = nome;
    this->coordenadaX = 0.0f; //0.0 é tratado como double
    this->coordenadaY = 0.0f;// definimls como float por isso temos de ter .f
}

float Empresa::getCoordenadaX() {
    return this->coordenadaX;
}

float Empresa::getCoordenadaY() {
    return this->coordenadaY;
}

CamiaoContainer& Empresa::getCamiaoContainer() {
    return this->camiaoContainer;
}

CamionistaContainer& Empresa::getCamionistaContainer() {
    return this->camionistaContainer;
}

CargaContainer& Empresa::getCargaContainer() {
    return this->cargaContainer;
}

RotaContainer& Empresa::getRotaContainer() {
    return this->rotaContainer;
}