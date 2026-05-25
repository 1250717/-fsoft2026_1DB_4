#include "..\..\Headers\Model\Camionista.h"

Camionista::Camionista(std::string nome){
    this->nome = nome;
    this->estado = "Disponivel"; // Predefinido no relatório 
    this->camiao = nullptr; // Predefinido no relatório 
}

void Camionista::setCamiao(Camiao *camiao){
    this->camiao = camiao;
}

void Camionista::setEstado(std::string estado){
    this->estado = estado;
}



Camiao* Camionista::getCamiao(){
    return this->camiao;
}

std::string Camionista::getNome(){
    return this->nome;
}

std::string Camionista::getEstado() {
    return this->estado;
}

