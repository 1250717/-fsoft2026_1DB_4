#ifndef MENUGESTOR_H
#define MENUGESTOR_H

#include <string>
#include <vector>
#include "..\Dtos\CamiaoDTO.h"
#include "..\Dtos\CamionistaDTO.h"
#include "..\Dtos\RotaDTO.h"
#include "..\Dtos\CargaDTO.h"
#include "..\Model\Localidade.h"
#include "..\Model\Camionista.h"


class MenuGestor{
private:
void listarCamioes(std::vector<CamiaoDTO> camioes);
void listarCargas(std::vector<CargaDTO> cargas);
void listarCamionistas(std::vector<CamionistaDTO> camionistas);


//São private porque só são usadas internamente pelo MenuGestor
public:

    int mostrarOpcoes();

    std::string pedirNomeGestor();
    std::string pedirNomeCamionista();
    std::string pedirMatricula();
    std::string pedirSelecaoCamiao(std::vector<CamiaoDTO> camioes);

    bool pedirConfirmacao();

    void mostrarSucessoRemoverCamiao(std::vector<CamiaoDTO> camioes);
    std::string pedirDestinoCarga(std::vector<Localidade> localidades);
    
    float pedirCapacidadeMaxima();
    float pedirPesoCarga();

    void mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes);
    
    void mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas);
    void visualizarCadastros(std::vector<CamiaoDTO> camioes, std::vector<CamionistaDTO> camionistas, std::vector<CargaDTO> cargas);
    void mostrarSucessoRegistarCarga(std::vector<CargaDTO> cargas);

    void mostrarErro(std::string mensagem);
    void mostrarRotasConcluidas(std::vector<RotaDTO> rotas);

    std::string pedirSelecaoCamionista(std::vector<CamionistaDTO> camionistas);
    void mostrarSucessoRemoverCamionista(std::vector<CamionistaDTO> camionistas);
    
    void mostrarCamionistasDisponiveis(std::vector<CamionistaDTO> camionistas);
    void mostrarCamioesDisponiveis(std::vector<CamiaoDTO> camioes);
    void mostrarSucessoAtribuicao(std::string nomeCamionista, std::string matricula);

    int pedirSelecaoCarga(std::vector<CargaDTO> cargas);
    void mostrarSucessoEliminarCarga(std::vector<CargaDTO> cargas);
};


#endif