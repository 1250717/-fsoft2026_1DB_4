#ifndef MENUGESTOR_H
#define MENUGESTOR_H

#include <string>
#include <vector>
#include "..\Model\CamiaoDTO.h"
#include "..\Model\CamionistaDTO.h"


class MenuGestor{
public:

    int mostrarOpcoes();

    std::string pedirNomeGestor();
    std::string pedirNomeCamionista();
    std::string pedirMatricula();
    
    float pedirCapacidadeMaxima();

    void mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes);
    void mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas);

    void mostrarErro(std::string mensagem);
};


#endif