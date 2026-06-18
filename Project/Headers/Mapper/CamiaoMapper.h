#ifndef CAMIAOMAPPER_H
#define CAMIAOMAPPER_H

#include "..\Model\Camiao.h"
#include "..\Dtos\CamiaoDTO.h"

class CamiaoMapper {
public:
    static CamiaoDTO toDTO(Camiao &camiao) {
        CamiaoDTO dto;
        dto.matricula = camiao.getMatricula();
        dto.capacidadeMaxima = camiao.getCapacidadeMaxima();
        dto.capacidadeDisponivel = camiao.getCapacidadeDisponivel();
        dto.estado = camiao.getEstado();
        return dto;
    }
};

#endif