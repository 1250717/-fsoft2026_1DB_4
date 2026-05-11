#ifndef CAMIAODTO_H
#define CAMIAODTO_H

#include <string>
#include <vector>

class CamiaoDTO {
public:
    float capacidadeMaxima;
    float capacidadeDisponivel;
    std::vector<std::string> cargas;  // cargas atribuídas ao camião
    // cargas disponíveis vêm do CargaContainer, não do Camiao — usar CargaDTO separado
};

#endif