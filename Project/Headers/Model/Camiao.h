#ifndef CAMIAO_H
#define CAMIAO_H

#include <string>
#include <vector>
#include "Carga.h"


class Camionista;

class Camiao{
private:
    std::string matricula;
    std::string estado;
    float capacidadeMaxima;
    float capacidadeDisponivel;

    std::vector<Carga*> cargas;

    Camionista *camionista;

public:
    Camiao(std::string matricula, float capacidadeMaxima);

    void setCamionista(Camionista *camionista);

    void setEstado(std::string estado);

    bool temCargas();

    Camionista *getCamionista();

    bool temCargasPorEstado(std::string estado);

    float getCapacidadeDisponivel();

    void setCapacidadeDisponivel(float valor);

    std::string getMatricula();

    float getCapacidadeMaxima();

    std::string getEstado();

    std::vector<Carga*>& getCargas();

    void adicionarCarga(Carga *carga); //criamos uma variavel carga do tipo ponteiro, passamos um endereco de memoria

    void removerCarga(Carga *carga);

};
#endif