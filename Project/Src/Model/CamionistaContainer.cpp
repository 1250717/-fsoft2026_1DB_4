#include "Project\Headers\Model\CamionistaContainer.h"

void CamionistaContainer::guardar(Camionista camionista){
    camionistas.push_back(camionista);
}

Camionista* CamionistaContainer::procurar(std::string nome){
    for(int i=0; i<camionistas.size(); i++){
        if(camionistas[i].getNome() == nome){
            return &camionistas[i];
        }
    }
    return nullptr;
}