#include "Project\Headers\Model\Camiao.h"


Camiao::Camiao(std::string matricula, float capacidadeMaxima) {
    this->matricula = matricula;
    this->capacidadeMaxima = capacidadeMaxima;
    this->capacidadeDisponivel = capacidadeMaxima; // Inicialmente o peso disponível é o total
    
    this->estado = "Disponível"; // Predefinido no relatório 
    this->camionista = nullptr;  // Predefinido no relatório
}

void Camiao::setCamionista(Camionista *camionista){
    this->camionista = camionista;
}