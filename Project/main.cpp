#include "Headers\Model\Empresa.h"
#include "Headers\Service\CamionistaService.h"
#include "Headers\Service\GestorService.h"
#include "Headers\Controller\MenuPrincipalController.h"
#include "Headers\Repository\GeneralRepository.h"
 
int main() {
    // Singleton — a classe recusa ser criada mais do que uma vez
    // Empresa* e1 = Empresa::getInstance(); // cria na primeira vez
    // Empresa* e2 = Empresa::getInstance(); // devolve a mesma — nao cria outra

    // Nao Singleton — como esta agora:
    // Empresa empresa("12345678", "Empresa Transportes"); // nos criamos o objeto
    // nada impede que alguem faca:
    // Empresa empresa1("111", "Empresa A");
    // Empresa empresa2("222", "Empresa B"); // segunda empresa — possivel
    // nos somos responsaveis por criar uma so e passar para quem precisa

    // inicializa a unica instancia da empresa
    Empresa::getInstance("12345678", "Empresa Transportes");

    // os restantes vao buscar a empresa internamente via Empresa::getInstance()
    GeneralRepository repository;
    repository.carregar();

    CamionistaService camionistaService;
    GestorService gestorService;
 
    MenuPrincipalController controller(&camionistaService, &gestorService);
    controller.mostrarMenu();
 
    repository.guardar();
 
    return 0;
}