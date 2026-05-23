#ifndef CARGAMAPPER_H
#define CARGAOMAPPER_H

#include "..\Model\Carga.h"
#include "..\Dtos\CargaDTO.h"

class CargaMapper {
public:
    static CargaDTO toDTO(Carga &carga) {
        CargaDTO dto;
        dto.peso = carga.getPeso();
        dto.nomeDestino = carga.getDestino()->getNome();
        dto.estado = carga.getEstado();
        return dto;
    }
};

#endif