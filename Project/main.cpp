#include "Headers\Model\Empresa.h"
#include "Headers\Service\CamionistaService.h"
#include "Headers\Service\GestorService.h"
#include "Headers\Controller\MenuPrincipalController.h"
#include "Headers\Repository\GeneralRepository.h"

int main() {
    Empresa empresa("12345678", "Empresa Transportes");

    GeneralRepository repository(
        &empresa.getCamionistaContainer(),
        &empresa.getCamiaoContainer(),
        &empresa.getCargaContainer(),
        &empresa.getRotaContainer(),
        &empresa.getLocalidadeContainer()
    );

    repository.carregar();

    CamionistaService camionistaService(&empresa.getCamionistaContainer());
    
    GestorService gestorService(
        &empresa.getCamionistaContainer(),
        &empresa.getCamiaoContainer(),
        &empresa.getCargaContainer(),
        &empresa.getRotaContainer()
    );

    MenuPrincipalController controller(&camionistaService, &gestorService);
    controller.mostrarMenu();
}