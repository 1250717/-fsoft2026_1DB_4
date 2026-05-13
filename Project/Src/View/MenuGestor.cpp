#include "Project\Headers\View\MenuGestor.h"
#include "Project\Headers\Controller\GestorController.h"
#include "Project\Headers\Model\CamiaoContainer.h"
#include "Project\Headers\Model\CamionistaContainer.h"
#include "Project\Headers\Model\CargaContainer.h"
#include "Project\Headers\Model\RotaContainer.h"
#include <iostream>

using namespace std;

MenuGestor::MenuGestor (GestorController *controller){
    this->controller = controller;
}
