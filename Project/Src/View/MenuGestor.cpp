#include "..\..\Headers\View\MenuGestor.h"
#include <iostream>


int MenuGestor::mostrarOpcoes(){
    std::cout << "\n -------- Gerir Empresa --------\n";
    std::cout << "\n 1 - Registar Camião";
    std::cout << "\n 2 - Registar Camionista";
    std::cout << "\n 3 - Registar Carga";
    std::cout << "\n 4 - Atribuir camionista a camião";
    std::cout << "\n 5 - Remover Camião";
    std::cout << "\n 6 - Remover Camionista";
    std::cout << "\n 7 - Eliminar Carga";
    std::cout << "\n 8 - Visualizar Cadastros";
    std::cout << "\n 9 - Visualizar Rotas Concluidas";
    std::cout << "\n 0 - Voltar para menu principal";
    std::cout << "\n Opcao: ";

    int opcao;
    std::cin >> opcao;
    return opcao;
}

std::string MenuGestor::pedirNomeGestor(){
    std::cout << "Nome do Gestor: ";
    std::string nome;
    std::cin >> nome;
    return nome;
}

std::string MenuGestor::pedirNomeCamionista(){
    std::cout << "Nome do Camionista a adicionar: ";
    std::string nome;
    std::cin >> nome;
    return nome;
}

std::string MenuGestor::pedirMatricula(){
    std::cout << "Introduza matricula: ";
    std::string matricula;
    std::cin >> matricula;
    return matricula;
}

float MenuGestor::pedirCapacidadeMaxima(){
    std::cout << "Introduza capacidade maxima: ";
    float capacidadeMaxima;
    std::cin >> capacidadeMaxima;
    return capacidadeMaxima;
}

void MenuGestor::mostrarErro(std::string mensagem){
    std::cout << "\nErro: " << mensagem << "\n";
}

void MenuGestor::mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes){
    std::cout << "\nCamiao registado com sucesso!\n";
    std::cout << "\n---- Lista de Camioes ----\n";
    for(int i = 0; i < camioes.size(); i++){
        std::cout << i+1 << ". " << camioes[i].matricula 
                  << " | Cap. Max: " << camioes[i].capacidadeMaxima
                  << " | Cap. Disp: " << camioes[i].capacidadeDisponivel
                  << " | Estado: " << camioes[i].estado << "\n";
    }
}

void MenuGestor::mostrarSucessoRemoverCamiao(std::vector<CamiaoDTO> camioes){
    std::cout << "\nCamiao removido com sucesso!\n";
}

std::string MenuGestor::pedirSelecaoCamiao(std::vector<CamiaoDTO> camioes){
    while(true){
        std::cout << "\n---- Lista de Camioes ----\n";
        for(int i = 0; i < camioes.size(); i++){
            std::cout << i+1 << ". " << camioes[i].matricula
                      << " | Estado: " << camioes[i].estado << "\n";
        }
        std::cout << "Introduza o indice do camiao a remover: ";
        int indice;
        std::cin >> indice;

        if(indice >= 1 && indice <= camioes.size()){
            return camioes[indice-1].matricula;
        }
        std::cout << "\nIndice invalido. Tente novamente.\n";
    }
}

bool MenuGestor::pedirConfirmacao(){
    std::cout << "\nTem a certeza? (s/n): ";
    char resposta;
    std::cin >> resposta;
    return resposta == 's';
}

void MenuGestor::mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas){
    std::cout << "\nCamionista registado com sucesso!\n";
    std::cout << "\n---- Lista de Camionistas ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
}