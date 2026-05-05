#include "Project\Headers\Model\Camiao.h"
#include "Project\Headers\Model\Camionista.h"
#include "Project\Headers\Model\Carga.h"


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

void Camiao::setEstado(std::string estado){
    this->estado = estado;
}

bool Camiao::temCargas(){ //size() Este método devolve o número exato de elementos (cargas) presentes na lista.
    if(cargas.size() >0){//A classe std::list tem um atributo privado: __size_
        return true; //cargas.size() apenas retorna esse valor
    }//pushback adiciona a essa variavel e remove() retira a essa variavel
    else return false;
}

Camionista *Camiao::getCamionista(){
    return this->camionista;
}

bool Camiao::temCargasPorEstado(std::string estado){
    for(int i=0; i<cargas.size(); i++){
        if(cargas[i]->getEstado() == estado){
            return true;
        }
    }
    return false;
}
