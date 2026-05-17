#ifndef CAMIONISTAMAPPER_H
#define CAMIONISTAMAPPER_H

#include "..\Model\Camionista.h"
#include "..\Model\CamionistaDTO.h"

class CamionistaMapper {
public:
    static CamionistaDTO toDTO(Camionista &camionista) {
        CamionistaDTO dto;
        dto.nome = camionista.getNome();
        dto.estado = camionista.getEstado();
        return dto;
    }
};

#endif