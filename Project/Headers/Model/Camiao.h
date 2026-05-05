#include <string>
#include <list>
#include "Carga.h"


class Camionista;

class Camiao{
private:
    std::string matricula;
    std::string estado;
    float capacidadeMaxima;
    float capacidadeDisponivel;

    std::list<Carga*> cargas;

    Camionista *camionista;

public:
    Camiao(std::string matricula, float capacidadeMaxima);

    void setCamionista(Camionista *camionista);

};