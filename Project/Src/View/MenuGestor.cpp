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

float MenuGestor::pedirPesoCarga(){
    std::cout << "Introduz o peso da carga (Kg): ";
    float peso;
    std::cin >> peso;
    return peso;
}

std::string MenuGestor::pedirDestinoCarga(std::vector<Localidade> localidades){
    std::cout << "\n---- Localidades disponiveis ----\n";
    for(int i = 0; i < localidades.size(); i++){
        std::cout << i+1 << ". " << localidades[i].getNome() << "\n";
    }
    std::cout << "Introduza o nome do destino: ";
    std::string nomeDestino;
    std::cin >> nomeDestino;
    return nomeDestino;
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

void MenuGestor::mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas){
    std::cout << "\nCamionista registado com sucesso!\n";
    std::cout << "\n---- Lista de Camionistas ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
}

void MenuGestor::mostrarSucessoRegistarCarga(std::vector<CargaDTO> cargas){
    std::cout << "\nCarga registada com sucesso!\n";
    std::cout << "\n---- Lista de Cargas ----\n";
    for(int i = 0; i < cargas.size(); i++){
        std::cout << i+1 << ". Peso: " << cargas[i].peso 
                  << " Kg | Estado: " << cargas[i].estado 
                  << " | Destino: " << cargas[i].nomeDestino << "\n";
    }
}