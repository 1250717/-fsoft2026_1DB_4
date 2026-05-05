#include "Project\Headers\Model\Camionista.h"

Camionista::Camionista(std::string nome){
    this->nome = nome;
    this->estado = "Disponível"; // Predefinido no relatório 
    this->camiao = nullptr; // Predefinido no relatório 
}