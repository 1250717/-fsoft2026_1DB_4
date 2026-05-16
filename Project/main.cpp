#include "Headers\Model\Empresa.h"
#include "Headers\Service\CamionistaService.h"
#include "Headers\Controller\CamionistaController.h"
#include "Headers\View\MenuPrincipal.h"
#include "Headers\Controller\MenuPrincipalController.h"


int main() {
    Empresa empresa("12345678", "Empresa Transportes"); // cria os containers

    CamionistaService service(&empresa.getCamionistaContainer()); //ligacao service e o model

    MenuPrincipalController controller(&service); // controller do menu principal precisa de um service
    controller.mostrarMenu(); //chamar menu Principal
    //Menu principal Controller tem uma funcao mostrarmenu()
}