#ifndef MENUGESTOR_H
#define MENUGESTOR_H

#include <string>
#include <vector>
#include "..\Model\CamiaoDTO.h"


class MenuGestor{
public:

    int mostrarOpcoes();

    std::string pedirNome();
    std::string pedirMatricula();
    float pedirCapacidadeMaxima();

    void mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes);

    void mostrarErro(std::string mensagem);
};


#endif