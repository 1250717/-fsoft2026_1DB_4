#include "Headers\Model\Empresa.h"
#include "Headers\Service\CamionistaService.h"
#include "Headers\Service\GestorService.h"
#include "Headers\Controller\MenuPrincipalController.h"
#include "Headers\Repository\GeneralRepository.h"
 
int main() {
    // Criar a empresa
    Empresa empresa("12345678", "Empresa Transportes");
 
    // Criar o repositorio para carregar/guardar dados de ficheiros
    GeneralRepository repository(
        &empresa.getCamionistaContainer(),
        &empresa.getCamiaoContainer(),
        &empresa.getCargaContainer(),
        &empresa.getRotaContainer(),
        &empresa.getLocalidadeContainer()
    );
 
    // Carregar os dados guardados (se existirem)
    repository.carregar();
 
    // Criar os services - CamionistaService precisa de 3 containers
    CamionistaService camionistaService(
        &empresa.getCamionistaContainer(),
        &empresa.getCargaContainer(),
        &empresa.getRotaContainer()
    );
    
    GestorService gestorService(
        &empresa.getCamionistaContainer(),
        &empresa.getCamiaoContainer(),
        &empresa.getCargaContainer(),
        &empresa.getRotaContainer(),
        &empresa.getLocalidadeContainer()
    );
 
    // Iniciar o controlador principal
    MenuPrincipalController controller(&camionistaService, &gestorService);
    controller.mostrarMenu();
 
    // Guardar os dados antes de terminar
    repository.guardar();
 
    return 0;
}