#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "CamiaoContainer.h"
#include "CamionistaContainer.h"
#include "CargaContainer.h"
#include "RotaContainer.h"
#include "LocalidadeContainer.h"

class Empresa {
private:
    //Um atributo static pertence à classe — existe uma só cópia 
    //partilhada por todos os objetos, mesmo que não exista nenhum objeto criado.
    // guarda o ponteiro para a unica instancia que existe
    static Empresa* instance;

    std::string nif;
    std::string nome;
    float coordenadaX;
    float coordenadaY;
    CamiaoContainer camiaoContainer;
    CamionistaContainer camionistaContainer;
    CargaContainer cargaContainer;
    RotaContainer rotaContainer;
    LocalidadeContainer localidadeContainer;

    // construtor privado — impede criar Empresa com "Empresa e(...)"
    Empresa(std::string nif, std::string nome);

public:
    // unico ponto de acesso — cria na primeira vez, devolve a mesma nas seguintes
    static Empresa* getInstance(std::string nif = "", std::string nome = "");

    float getCoordenadaX();
    float getCoordenadaY();
    CamiaoContainer& getCamiaoContainer();
    CamionistaContainer& getCamionistaContainer();
    CargaContainer& getCargaContainer();
    RotaContainer& getRotaContainer();
    LocalidadeContainer& getLocalidadeContainer();
};

#endif