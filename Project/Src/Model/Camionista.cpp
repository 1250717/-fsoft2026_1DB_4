#include "..\..\Headers\Model\Camionista.h"
#include <stdexcept>
#include <cctype>

Camionista::Camionista(std::string nome){
    validarNome(nome);
    this->nome = nome;
    this->estado = "Disponivel";
    this->camiao = nullptr;
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

void Camionista::validarNome(std::string nome){
    if(nome.size() < 4 || nome.size() > 10){
        throw std::invalid_argument("Nome tem de ter entre 4 e 10 caracteres.");
    }
    for(int i = 0; i < nome.size(); i++){
        if(!isalpha(nome[i])){
            throw std::invalid_argument("Nome so pode conter letras.");
        }
    }
}

void Camionista::verificarDisponivel(){
    if(this->getCamiao() != nullptr){
        throw std::invalid_argument("Camionista ja tem camiao atribuido.");
    }
}
