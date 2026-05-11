#ifndef MENUCAMIONISTA_H
#define MENUCAMIONISTA_H
#include "CamionistaController.h"

class MenuCamionista{
private:
    CamionistaController *controller;
    std::string nomeCamionista;
public:
    MenuCamionista(CamionistaController *controller);
    void mostrar();
    bool login();//pergunta pelo nome, passa ao controller que passa ao service que vai buscar ao model

};

#endif