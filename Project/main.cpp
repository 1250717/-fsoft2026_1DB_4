#include "Headers\Model\Empresa.h"
#include "Headers\Service\CamionistaService.h"
#include "Headers\Service\GestorService.h"
#include "Headers\Controller\MenuPrincipalController.h"

int main() {
    Empresa empresa("12345678", "Empresa Transportes");

    CamionistaService camionistaService( &empresa.getCamionistaContainer(), &empresa.getCargaContainer(),&empresa.getRotaContainer());
    
    GestorService gestorService(
        &empresa.getCamionistaContainer(),
        &empresa.getCamiaoContainer(),
        &empresa.getCargaContainer(),
        &empresa.getRotaContainer()
    );

    MenuPrincipalController controller(&camionistaService, &gestorService);
    controller.mostrarMenu();
}