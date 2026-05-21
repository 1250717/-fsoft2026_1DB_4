#ifndef CARGAMAPPER_H
#define CARGAMAPPER_H

#include "../Model/Carga.h"
#include "../Dtos/CargaDTO.h"

class CargaMapper {
public:
    static CargaDTO toDTO(Carga &carga) {
        CargaDTO dto;
        dto.peso = carga.getPeso();
        dto.estado = carga.getEstado();
        dto.nomeDestino = carga.getDestino()->getNome();
        return dto;
    }
};

#endif