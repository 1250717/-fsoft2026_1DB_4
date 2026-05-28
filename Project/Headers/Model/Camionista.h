#ifndef CAMIONISTA_H
#define CAMIONISTA_H

#include <string>

class Camiao;

class Camionista {
private:
    std::string nome;
    std::string estado;
    Camiao* camiao;

public:
    Camionista(std::string nome);

    void setCamiao(Camiao* camiao);
    void setEstado(std::string estado);

    Camiao* getCamiao();
    std::string getNome();
    std::string getEstado();

    static bool validarNome(std::string nome);
};

#endif