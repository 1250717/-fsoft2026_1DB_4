#include <string>
#include <list>

class Camiao;

class Camionista{
private:
    std::string nome;
    std::string estado;
    Camiao* camiao;

public:
    Camionista(std::string nome);

    std::string getNome();
};