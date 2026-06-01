#include "..\..\Headers\Model\Camiao.h"
#include "..\..\Headers\Model\Camionista.h"
#include "..\..\Headers\Model\Carga.h"
#include <stdexcept>


Camiao::Camiao(std::string matricula, float capacidadeMaxima) {
    validarMatricula(matricula);
    validarCapacidade(capacidadeMaxima);

    this->matricula = matricula;
    this->capacidadeMaxima = capacidadeMaxima;
    this->capacidadeDisponivel = capacidadeMaxima;
    this->estado = "Disponivel";
    this->camionista = nullptr;
}

void Camiao::validarMatricula(std::string matricula){
    if(matricula.size() != 8 || matricula[2] != '-' || matricula[5] != '-'){
        throw std::invalid_argument("Formato da matricula invalido.");
    }
    if(matricula[0] < 'A' || matricula[0] > 'Z') throw std::invalid_argument("Formato da matricula invalido.");
    if(matricula[1] < 'A' || matricula[1] > 'Z') throw std::invalid_argument("Formato da matricula invalido.");
    if(matricula[3] < '0' || matricula[3] > '9') throw std::invalid_argument("Formato da matricula invalido.");
    if(matricula[4] < '0' || matricula[4] > '9') throw std::invalid_argument("Formato da matricula invalido.");
    if(matricula[6] < 'A' || matricula[6] > 'Z') throw std::invalid_argument("Formato da matricula invalido.");
    if(matricula[7] < 'A' || matricula[7] > 'Z') throw std::invalid_argument("Formato da matricula invalido.");
}

void Camiao::validarCapacidade(float capacidade){
    if(capacidade < 100 || capacidade > 10000){
        throw std::invalid_argument("Capacidade tem de ser entre 100 e 10000 Kg.");
    }
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

float Camiao::getCapacidadeDisponivel(){
    return this->capacidadeDisponivel;
}

void Camiao::setCapacidadeDisponivel(float valor){
    this->capacidadeDisponivel = valor;
}

std::string Camiao::getMatricula(){
    return this->matricula;
}

float Camiao::getCapacidadeMaxima(){
    return this->capacidadeMaxima;
}

std::string Camiao::getEstado(){
    return this->estado;
}

std::vector<Carga*>& Camiao::getCargas(){
    return this->cargas;
}

void Camiao::adicionarCarga(Carga *carga){
    cargas.push_back(carga);
}

void Camiao::removerCarga(Carga *carga){
    for(int i = 0; i<cargas.size(); i++){
        if(cargas[i] == carga){
            cargas.erase(cargas.begin() + i);
            return;
        }
    }
}