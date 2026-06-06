#ifndef ROTAMAPPER_H
#define ROTAMAPPER_H
 
#include "..\Model\Rota.h"
#include "..\Dtos\RotaDTO.h"
 
class RotaMapper {
public:
    static RotaDTO toDTO(Rota &rota) {
        RotaDTO dto;
        dto.idRota = rota.getIdRota();
        dto.distanciaTotal = rota.getDistanciaTotal();
        dto.nomeCamionista = rota.getNomeCamionista();
        dto.matriculaCamiao = rota.getMatriculaCamiao();
        dto.destinosOrdemFIFO = rota.getDestinos(); // copia direta — ambos sao vector<string>
        return dto;
    }
};
 
#endif


