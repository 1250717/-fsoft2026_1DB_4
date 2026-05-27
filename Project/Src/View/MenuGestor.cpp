#include "..\..\Headers\View\MenuGestor.h"
#include <iostream>
#include <limits>


int MenuGestor::mostrarOpcoes(){
    std::cout << "\n -------- Gerir Empresa --------\n";
    std::cout << "\n 1 - Registar Camiao";
    std::cout << "\n 2 - Registar Camionista";
    std::cout << "\n 3 - Registar Carga";
    std::cout << "\n 4 - Atribuir Camionista a Camiao";
    std::cout << "\n 5 - Remover Camiao";
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
    float capacidadeMaxima;
    while(true){
        std::cout << "Introduza capacidade maxima (Kg): ";
        std::cin >> capacidadeMaxima;
        if(std::cin.fail()){
            std::cin.clear(); // limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta input invalido
            std::cout << "\nErro: introduza apenas numeros.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o \n do buffer
            return capacidadeMaxima;
        }
    }
}

float MenuGestor::pedirPesoCarga(){
    float peso;
    while(true){
        std::cout << "Introduz o peso da carga (Kg): ";
        std::cin >> peso;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nErro: introduza apenas numeros.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o \n do buffer
            return peso;
        }
    }
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

void MenuGestor::mostrarSucessoRemoverCamiao(std::vector<CamiaoDTO> camioes){
    std::cout << "\nCamiao removido com sucesso!\n";
    std::cout << "\n---- Lista de Camioes ----\n";
    for(int i = 0; i < camioes.size(); i++){
        std::cout << i+1 << ". " << camioes[i].matricula 
                  << " | Cap. Max: " << camioes[i].capacidadeMaxima
                  << " | Cap. Disp: " << camioes[i].capacidadeDisponivel
                  << " | Estado: " << camioes[i].estado << "\n";
    }
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

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Indice invalido. Tente novamente.\n";
            continue;
        }

        if(indice >= 1 && indice <= (int)camioes.size()){
            return camioes[indice-1].matricula;
        } else {
            std::cout << "\nIndice invalido. Tente novamente.\n";
        }
    }
}

bool MenuGestor::pedirConfirmacao(){
    std::cout << "\nTem a certeza? (s/n): ";
    char resposta;
    std::cin >> resposta;
    return resposta == 's' || resposta == 'S';
}

void MenuGestor::mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas){
    std::cout << "\nCamionista registado com sucesso!\n";
    std::cout << "\n---- Lista de Camionistas ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
}



// visualizar rotas concluidas
void MenuGestor::mostrarRotasConcluidas(std::vector<RotaDTO> rotas){
    std::cout << "\n---- Rotas Concluidas ----\n";
    for(int i = 0; i < rotas.size(); i++){
        std::cout << "\nRota #" << rotas[i].idRota << "\n";
        std::cout << "  Camionista: " << rotas[i].nomeCamionista << "\n";
        std::cout << "  Camiao: " << rotas[i].matriculaCamiao << "\n";
        std::cout << "  Distancia total: " << rotas[i].distanciaTotal << "\n";
        std::cout << "  Destinos (ordem FIFO):\n";
        for(int j = 0; j < rotas[i].destinosOrdemFIFO.size(); j++){
            std::cout << "    " << j+1 << ". " << rotas[i].destinosOrdemFIFO[j] << "\n";
        }
    }
    std::cout << "--------------------------\n";
}

void MenuGestor::visualizarCadastros(std::vector<CamiaoDTO> camioes, std::vector<CamionistaDTO> camionistas){
    std::cout << "\n---- Lista de Camionistas ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }

    std::cout << "\n---- Lista de Camioes ----\n";
    for(int i = 0; i < camioes.size(); i++){
        std::cout << i+1 << ". " << camioes[i].matricula 
                  << " | Cap. Max: " << camioes[i].capacidadeMaxima
                  << " | Cap. Disp: " << camioes[i].capacidadeDisponivel
                  << " | Estado: " << camioes[i].estado << "\n";
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

std::string MenuGestor::pedirSelecaoCamionista(std::vector<CamionistaDTO> camionistas){
    while (true){   
        std::cout << "\n---- Lista de Camionistas ----\n";
        for(int i = 0; i < camionistas.size(); i++){
            std::cout << i+1 << "." << camionistas[i].nome
                    << " | Estado: " << camionistas[i].estado << "\n";
        }
        std::cout << "Introduz o indíce do camionista a remover: ";
        int indice;
        std::cin >> indice;
        
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Indice invalido. Tente novamente.\n";
            continue;
        }

        if(indice >= 1 && indice <= (int)camionistas.size()){
            return camionistas[indice-1].nome;
        } else {
            std::cout << "\nIndice invalido. Tente novamente.\n";
        }
    }
}

void MenuGestor::mostrarSucessoRemoverCamionista(std::vector<CamionistaDTO> camionistas){
    std::cout << "\nCamionista removido com sucesso!\n";
    std::cout << "\n---- Lista de Camionistas ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
}

// Mostra a lista de camionistas que ainda nao tem camiao atribuido
void MenuGestor::mostrarCamionistasDisponiveis(std::vector<CamionistaDTO> camionistas){
    std::cout << "\n---- Camionistas Disponiveis ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
    std::cout << "---------------------------------\n";
}
 
// Mostra a lista de camioes que ainda nao tem camionista atribuido
void MenuGestor::mostrarCamioesDisponiveis(std::vector<CamiaoDTO> camioes){
    std::cout << "\n---- Camioes Disponiveis ----\n";
    for(int i = 0; i < camioes.size(); i++){
        std::cout << i+1 << ". " << camioes[i].matricula
                  << " | Cap. Max: " << camioes[i].capacidadeMaxima
                  << " | Estado: " << camioes[i].estado << "\n";
    }
    std::cout << "-----------------------------\n";
}
 
// Mensagem de sucesso apos atribuicao
void MenuGestor::mostrarSucessoAtribuicao(std::string nomeCamionista, std::string matricula){
    std::cout << "\nAtribuicao realizada com sucesso!\n";
    std::cout << "Camionista " << nomeCamionista << " esta agora atribuido ao camiao " << matricula << ".\n";
}

int MenuGestor::pedirSelecaoCarga(std::vector<CargaDTO> cargas){
    std::cout << "\n---- Lista de Cargas ----\n";
    for(int i = 0; i < cargas.size(); i++){
        std::cout << i+1 << ". Peso: " << cargas[i].peso
                  << " | Estado: " << cargas[i].estado
                  << " | Destino: " << cargas[i].nomeDestino << "\n";
    }

    std::cout << "Introduz o indice da carga a eliminar: ";
    int indice;
    std::cin >> indice;
    return indice-1;
}

void MenuGestor::mostrarSucessoEliminarCarga(std::vector<CargaDTO> cargas){
    std::cout << "\nCarga eliminada com sucesso!\n";
    std::cout << "\n---- Lista de Cargas ----\n";
    for(int i = 0; i < cargas.size(); i++){
        std::cout << i+1 << ". Peso: " << cargas[i].peso
                  << " kg | Estado: " << cargas[i].estado
                  << " | Destino: " << cargas[i].nomeDestino << "\n";
    }
}