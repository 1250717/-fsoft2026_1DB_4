#include "Project\Headers\Model\Empresa.h"
#include "Project\Headers\Service\CamionistaService.h"
#include "Project\Headers\Controller\CamionistaController.h"
#include "Project\Headers\View\MenuPrincipal.h"

int main() {
    Empresa empresa("12345678", "Empresa Transportes");
    
    CamionistaService camionistaService(&empresa.getCamionistaContainer());
    CamionistaController camionistaController(&camionistaService);
    
    MenuPrincipal menu(camionistaController);
    menu.mostrar();
    
    return 0;
}