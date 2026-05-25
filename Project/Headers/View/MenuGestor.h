#ifndef MENUGESTOR_H
#define MENUGESTOR_H

#include <string>
#include <vector>
#include "..\Dtos\CamiaoDTO.h"
#include "..\Dtos\CamionistaDTO.h"
#include "..\Dtos\CargaDTO.h"
#include "..\Model\Localidade.h"


class MenuGestor{
public:

    int mostrarOpcoes();

    std::string pedirNomeGestor();
    std::string pedirNomeCamionista();
    std::string pedirMatricula();
    std::string pedirDestinoCarga(std::vector<Localidade> localidades);
    
    float pedirCapacidadeMaxima();
    float pedirPesoCarga();

    void mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes);
    void mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas);
    void mostrarSucessoRegistarCarga(std::vector<CargaDTO> cargas);

    void mostrarErro(std::string mensagem);
};


#endif