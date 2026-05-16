#ifndef CAMIONISTADTO_H
#define CAMIONISTADTO_H

#include <string>

class CamionistaDTO {
public:
    std::string nome;
    std::string estado;
    std::string matriculaCamiao; // matrícula do camião atribuído (vazio se não tiver)
};

#endif