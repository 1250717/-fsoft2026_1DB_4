#include "..\..\Headers\View\MenuCamionista.h"
#include <iostream>

#include <limits>
 
using namespace std;
 
std::string MenuCamionista::pedirNome() {
    std::cout << "Nome do camionista: ";
    std::string nome;
    std::cin >> nome;
    return nome;
}
 
int MenuCamionista::mostrarOpcoes(){
    std::cout << "\n--------- Menu Camionista ---------\n";
    std::cout << "1. Visualizar estado do camiao\n";
    std::cout << "2. Adicionar Carga\n";
    std::cout << "3. Remover Carga\n";
    std::cout << "4. Iniciar Entrega\n";
    std::cout << "0. Logout\n";
    std::cout << "Escolha uma opcao: ";

    int opcao;
    std::cin >> opcao;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    return opcao;
}
 
void MenuCamionista::mostrarEstadoCamiao(CamiaoDTO camiao){
    std::cout << "\n--- Estado do Camiao ---\n";
    std::cout << "Capacidade maxima: " << camiao.capacidadeMaxima << "\n";
    std::cout << "Capacidade disponivel: " << camiao.capacidadeDisponivel << "\n";
    
    std::cout << "Cargas atribuidas:\n";
    if(camiao.cargas.empty()){
        std::cout << "  Sem cargas atribuidas.\n";
    } else {
        for(int i = 0; i < camiao.cargas.size(); i++){
            std::cout << "  " << i+1 << ". " << camiao.cargas[i] << "\n";
        }
    }
    std::cout << "------------------------\n";
}
 

 
void MenuCamionista::mostrarCargasDisponiveis(std::vector<CargaDTO> cargas){
    std::cout << "\n---- Cargas Disponiveis ----\n";
    for(int i = 0; i < cargas.size(); i++){
        std::cout << cargas[i].indice << ". "
                  << "Peso: " << cargas[i].peso
                  << " | Destino: " << cargas[i].nomeDestino
                  << " | Estado: " << cargas[i].estado << "\n";
    }
    std::cout << "----------------------------\n";
}
 
int MenuCamionista::pedirIndiceCarga(){
    std::cout << "Introduza o indice da carga: ";
    int indice;
    std::cin >> indice;
    return indice;
}
 
void MenuCamionista::mostrarSucessoAdicionarCarga(CamiaoDTO camiao){
    std::cout << "\nCarga adicionada com sucesso!\n";
    mostrarEstadoCamiao(camiao);
}
 
void MenuCamionista::mostrarErro(std::string mensagem){
    std::cout << "\nErro: " << mensagem << "\n";
}
 
 
void MenuCamionista::mostrarCargasDoCamiao(std::vector<CargaDTO> cargas){
    std::cout << "\n---- Cargas Atribuidas ao Camiao ----\n";
    for(int i = 0; i < cargas.size(); i++){
        std::cout << cargas[i].indice << ". "
                  << "Peso: " << cargas[i].peso
                  << " | Destino: " << cargas[i].nomeDestino
                  << " | Estado: " << cargas[i].estado << "\n";
    }
    std::cout << "-------------------------------------\n";
}
 
bool MenuCamionista::pedirConfirmacao(){
    std::cout << "Confirma a remocao? (s/n): ";
    std::string resposta;
    std::cin >> resposta;
    return (resposta == "s" || resposta == "S");
}
 
void MenuCamionista::mostrarSucessoRemoverCarga(CamiaoDTO camiao){
    std::cout << "\nCarga removida com sucesso!\n";
    mostrarEstadoCamiao(camiao);
}

void MenuCamionista::mostrarItinerario(RotaDTO rota){
    std::cout << "\n---- Itinerario da Rota ----\n";
    std::cout << "Camionista: " << rota.nomeCamionista << "\n";
    std::cout << "Camiao: " << rota.matriculaCamiao << "\n";
    std::cout << "Partida: Empresa (0,0)\n";
    std::cout << "Destinos (ordem FIFO):\n";
    for(int i = 0; i < rota.destinosOrdemFIFO.size(); i++){
        std::cout << "  " << i+1 << ". " << rota.destinosOrdemFIFO[i] << "\n";
    }
    std::cout << "Distancia total: " << rota.distanciaTotal << "\n";
    std::cout << "----------------------------\n";
}
 
void MenuCamionista::mostrarSucessoIniciarEntrega(){
    std::cout << "\nEntrega concluida com sucesso!\n";
    std::cout << "Camionista e camiao voltaram ao estado Disponivel.\n";
}





