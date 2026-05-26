#ifndef MENUCAMIONISTA_H
#define MENUCAMIONISTA_H

#include <string>
#include "..\Dtos\CamiaoDTO.h"
#include "..\Dtos\CargaDTO.h"
#include "..\Dtos\RotaDTO.h"

class MenuCamionista {
public:
    std::string pedirNome();
    int mostrarOpcoes();
    void mostrarEstadoCamiao(CamiaoDTO camiao);
    
    void mostrarCargasDisponiveis(std::vector<CargaDTO> cargas);
    int pedirIndiceCarga();
    void mostrarSucessoAdicionarCarga(CamiaoDTO camiao);
    void mostrarErro(std::string mensagem);

    void mostrarCargasDoCamiao(std::vector<CargaDTO> cargas);
    bool pedirConfirmacao();
    void mostrarSucessoRemoverCarga(CamiaoDTO camiao);

    void mostrarItinerario(RotaDTO rota);
    void mostrarSucessoIniciarEntrega();

};

#endif