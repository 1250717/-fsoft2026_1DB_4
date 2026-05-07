#ifndef CAMIONISTASERVICE_H
#define CAMIONISTASERVICE_H

#include <string>
#include <CamionistaContainer.h>

class CamionistaService{
private:
    CamionistaContainer *container;

public:
    CamionistaService(CamionistaContainer *container);

    bool verificarLogin(std::string nome);

};

#endif