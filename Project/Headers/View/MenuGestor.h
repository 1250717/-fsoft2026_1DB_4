#ifndef MENUGESTOR_H
#define MENUGESTOR_H

class MenuGestor{
private:
    GestorController *controller;
public:
    MenuGestor(GestorController *controller);

    void mostrar();
};


#endif