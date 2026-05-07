#include "Project\Headers\Service\CamionistaService.h"

CamionistaService::CamionistaService(CamionistaContainer *container){
    this->container = container;
}

bool CamionistaService::verificarLogin(std::string nome){
    Camionista *c = container->procurar(nome);
    if(c != nullptr){
        return true;
    }
    return false;

}
