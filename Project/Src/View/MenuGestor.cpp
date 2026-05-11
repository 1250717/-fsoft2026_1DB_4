#include "Project\Headers\View\MenuGestor.h"
#include "Project\Headers\Controller\GestorController.h"
#include "Project\Headers\Model\CamiaoContainer.h"
#include "Project\Headers\Model\CamionistaContainer.h"
#include "Project\Headers\Model\CargaContainer.h"
#include "Project\Headers\Model\RotaContainer.h"
#include <iostream>

using namespace std;

void MenuGestor::mostrar() {

    // O VIEW NAO RECEBE CONTAINERS RECEBE ACESSO AO CONTROLLER QUE TRATA DO RESTO
    CamiaoContainer camiaoContainer;
    CamionistaContainer camionistaContainer;
    CargaContainer cargaContainer;
    RotaContainer rotaContainer;

    GestorController controller(&camiaoContainer, &camionistaContainer,
                                &cargaContainer, &rotaContainer);

    while (true) {
        cout << "\n=== Menu Gestor ===\n";
        cout << "1. Registar Camiao\n";
        cout << "2. Registar Camionista\n";
        cout << "3. Registar Carga\n";
        cout << "4. Listar Camioes, Camionistas e Cargas\n";
        cout << "5. Atribuir Camionista a Camiao\n";
        cout << "6. Remover Camionista\n";
        cout << "7. Remover Carga\n";
        cout << "8. Remover Camiao\n";
        cout << "9. Ver Rotas Concluidas\n";
        cout << "0. Sair\n";
        cout << "Introduza opcao: ";

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            string matricula;
            float capacidade;
            cout << "Matricula do camiao: ";
            cin >> matricula;
            cout << "Capacidade maxima: ";
            cin >> capacidade;
            controller.registarCamiao(matricula, capacidade);

        } else if (opcao == 2) {
            string nome;
            cout << "Nome do camionista: ";
            cin >> nome;
            controller.registarCamionista(nome);

        } else if (opcao == 3) {
            float peso;
            string destino;
            cout << "Peso da carga: ";
            cin >> peso;
            cout << "Destino da carga: ";
            cin >> destino;
            controller.registarCarga(peso, destino);

        } else if (opcao == 4) {
            controller.listarTodos();

        } else if (opcao == 5) {
            string matricula, nome;
            cout << "Matricula do camiao: ";
            cin >> matricula;
            cout << "Nome do camionista: ";
            cin >> nome;
            controller.atribuirCamionista(matricula, nome);

        } else if (opcao == 6) {
            string nome;
            cout << "Nome do camionista a remover: ";
            cin >> nome;
            char confirmacao;
            cout << "Tem a certeza? (s/n): ";
            cin >> confirmacao;
            if (confirmacao == 's' || confirmacao == 'S') {
                controller.removerCamionista(nome);
            } else {
                cout << "Operacao cancelada.\n";
            }

        } else if (opcao == 7) {
            controller.listarTodos();
            int indice;
            cout << "Indice da carga a remover: ";
            cin >> indice;
            char confirmacao;
            cout << "Tem a certeza? (s/n): ";
            cin >> confirmacao;
            if (confirmacao == 's' || confirmacao == 'S') {
                controller.removerCarga(indice);
            } else {
                cout << "Operacao cancelada.\n";
            }

        } else if (opcao == 8) {
            string matricula;
            cout << "Matricula do camiao a remover: ";
            cin >> matricula;
            char confirmacao;
            cout << "Tem a certeza? (s/n): ";
            cin >> confirmacao;
            if (confirmacao == 's' || confirmacao == 'S') {
                controller.removerCamiao(matricula);
            } else {
                cout << "Operacao cancelada.\n";
            }

        } else if (opcao == 9) {
            controller.listarRotasConcluidas();

        } else if (opcao == 0) {
            break;

        } else {
            printf("Opcao invalida.\n");
        }
    }
}