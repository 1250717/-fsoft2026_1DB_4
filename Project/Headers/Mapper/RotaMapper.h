#ifndef ROTAMAPPER_H
#define ROTAMAPPER_H

#include "../Model/Rota.h"
#include "../Dtos/RotaDTO.h"

class RotaMapper {
public:
    static RotaDTO toDTO(Rota &rota) {
        RotaDTO dto;
        dto.idRota = rota.getIdRota();
        dto.distanciaTotal = rota.getDistanciaTotal();
        dto.nomeCamionista = rota.getNomeCamionista();
        dto.matriculaCamiao = rota.getMatriculaCamiao();
        std::vector<Carga>& cargas = rota.getCargas();
        for(int i = 0; i < cargas.size(); i++){
            dto.destinosOrdemFIFO.push_back(cargas[i].getDestino()->getNome());
        }
        return dto;
    }
};

#endif