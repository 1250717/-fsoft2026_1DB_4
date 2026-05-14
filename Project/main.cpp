#include "Headers\Model\Empresa.h"
#include "Headers\Service\CamionistaService.h"
#include "Headers\Controller\CamionistaController.h"
#include "Headers\View\MenuPrincipal.h"

int main() {
    Empresa empresa("12345678", "Empresa Transportes");
    //creator; cria os containers
    
    CamionistaService camionistaService(&empresa.getCamionistaContainer());
    CamionistaController camionistaController(&camionistaService);
    
    MenuPrincipal menu(camionistaController);
    menu.mostrar();
    
    return 0;
}