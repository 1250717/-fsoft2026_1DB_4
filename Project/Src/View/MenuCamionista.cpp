#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>

using namespace std;

std::string MenuCamionista::pedirNome() {
    std::cout << "Nome do camionista: ";
    std::string nome;
    std::cin >> nome;
    return nome;
}

int MenuCamionista::mostrarOpcoes(){
    std::cout << "\n1. Visualizar estado do camião\n";
    std::cout << "0. Logout\n";
    std::cout << "Escolha uma opção: ";

    int opcao;
    std::cin >> opcao;
    return opcao;
}

void MenuCamionista::mostrarEstadoCamiao(CamiaoDTO camiao){
    std::cout << "\n--- Estado do Camião ---\n";
    std::cout << "Capacidade máxima: " << camiao.capacidadeMaxima << "\n";
    std::cout << "Capacidade disponível: " << camiao.capacidadeDisponivel << "\n";
    
    std::cout << "Cargas atribuídas:\n";
    if(camiao.cargas.empty()){
        std::cout << "  Sem cargas atribuídas.\n";
    } else {
        for(int i = 0; i < camiao.cargas.size(); i++){
            std::cout << "  " << i+1 << ". " << camiao.cargas[i] << "\n";
        }
    }
    std::cout << "------------------------\n";
}