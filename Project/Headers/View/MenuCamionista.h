#ifndef MENUCAMIONISTA_H
#define MENUCAMIONISTA_H

#include <string>
#include "..\Dtos\CamiaoDTO.h"

class MenuCamionista {
public:
    std::string pedirNome();
    int mostrarOpcoes();
    void mostrarEstadoCamiao(CamiaoDTO camiao);
};

#endif