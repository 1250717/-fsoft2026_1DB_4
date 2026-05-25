#ifndef MENUGESTOR_H
#define MENUGESTOR_H

#include <string>
#include <vector>
#include "..\Dtos\CamiaoDTO.h"
#include "..\Dtos\CamionistaDTO.h"


class MenuGestor{
public:

    int mostrarOpcoes();

    std::string pedirNomeGestor();
    std::string pedirNomeCamionista();
    std::string pedirMatricula();
    std::string pedirSelecaoCamiao(std::vector<CamiaoDTO> camioes);

    bool pedirConfirmacao();

    void mostrarSucessoRemoverCamiao(std::vector<CamiaoDTO> camioes);
    
    float pedirCapacidadeMaxima();

    void mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes);
    
    void mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas);

    void mostrarErro(std::string mensagem);
};


#endif