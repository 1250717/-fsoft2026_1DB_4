#include "..\..\Headers\View\MenuGestor.h"
#include <iostream>
#include <limits>

// ==================== OPCOES ====================

int MenuGestor::mostrarOpcoes(){
    std::cout << "\n -------- Gerir Empresa --------\n";
    std::cout << "\n 1 - Registar Camiao";
    std::cout << "\n 2 - Registar Camionista";
    std::cout << "\n 3 - Registar Carga";
    std::cout << "\n 4 - Atribuir Camionista a Camiao";
    std::cout << "\n 5 - Remover Camiao";
    std::cout << "\n 6 - Remover Camionista";
    std::cout << "\n 7 - Eliminar Carga";
    std::cout << "\n 8 - Visualizar Registros";
    std::cout << "\n 9 - Visualizar Rotas Concluidas";
    std::cout << "\n 0 - Voltar para menu principal";
    std::cout << "\n Opcao: ";

    int opcao;
    std::cin >> opcao;
    return opcao;
}

// ==================== GESTOR ====================

std::string MenuGestor::pedirNomeGestor(){
    std::cout << " Nome do Gestor: ";
    std::string nome;
    std::cin >> nome;
    return nome;
}

// ==================== CAMIOES ====================

void MenuGestor::listarCamioes(std::vector<CamiaoDTO> camioes){
    std::cout << "\n---- Lista de Camioes ----\n";
    for(int i = 0; i < camioes.size(); i++){
        std::cout << i+1 << ". " << camioes[i].matricula 
                  << " | Cap. Max: " << camioes[i].capacidadeMaxima
                  << " | Cap. Disp: " << camioes[i].capacidadeDisponivel
                  << " | Estado: " << camioes[i].estado << "\n";
    }
}

std::string MenuGestor::pedirMatricula(){
    std::cout << "Introduza matricula (formato AA-00-AA) ou 'v' para voltar: ";
    std::string matricula;
    std::cin >> matricula;
    return matricula;
}

float MenuGestor::pedirCapacidadeMaxima(){
    while(true){
        std::cout << "\nIntroduza capacidade maxima (Kg): ";
        float capacidade;
        std::cin >> capacidade;
        // cin >> le apenas o que precisa para preencher a variavel
        // para quando encontra um espaco ou um caractere que nao faz parte de um float
        // ex: "500 abc" ou "500abc" → lê "500", o resto fica no buffer
        // ignore() descarta esse resto ate ao '\n' inclusive

        if(std::cin.fail()){
            // fail() — a leitura falhou (ex: "abc" nao e um float)
            //           o "abc\n" continua no buffer intacto
            std::cin.clear();
            // clear() — desbloqueia o cin para aceitar leituras futuras
            //            NAO descarta nada — o "abc\n" ainda esta no buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // ignore() — descarta tudo no buffer ate ao '\n' inclusive
            //             ex: buffer tinha "abc\n" → fica vazio
            std::cout << "Erro: introduza um numero.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // cin >> consumiu os digitos (ex: "500") e meteu-os em capacidade
        // no buffer ficou apenas o '\n' do Enter
        // se mais a frente houver um getline(), ele apanhava esse '\n'
        // e devolvia uma string vazia sem esperar pelo utilizador
        // ignore() descarta esse '\n' para evitar esse problema
        return capacidade;
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

void MenuGestor::mostrarSucessoRegistarCamiao(std::vector<CamiaoDTO> camioes){
    std::cout << "\nCamiao registado com sucesso!\n";
    listarCamioes(camioes);
}

void MenuGestor::mostrarSucessoRemoverCamiao(std::vector<CamiaoDTO> camioes){
    std::cout << "\nCamiao removido com sucesso!\n";
    listarCamioes(camioes);
}

// ==================== CAMIONISTAS ====================

void MenuGestor::listarCamionistas(std::vector<CamionistaDTO> camionistas){
    std::cout << "\n---- Lista de Camionistas ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
}

std::string MenuGestor::pedirNomeCamionista(){
    std::cout << "Nome do Camionista (ou 'v' para voltar): ";
    std::string nome;
    std::cin >> nome;
    return nome;
    //o cin >> aceita qualquer coisa numa string, 
    //incluindo números. O cin.fail() numa string nunca 
    //falha porque uma string aceita qualquer sequência de caracteres.
}

std::string MenuGestor::pedirSelecaoCamionista(std::vector<CamionistaDTO> camionistas){
    while(true){
        listarCamionistas(camionistas);
        std::cout << "Introduz o indice do camionista a remover: ";
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

// Mostra a lista de camionistas que ainda nao tem camiao atribuido
void MenuGestor::mostrarCamionistasDisponiveis(std::vector<CamionistaDTO> camionistas){
    std::cout << "\n---- Camionistas Disponiveis ----\n";
    for(int i = 0; i < camionistas.size(); i++){
        std::cout << i+1 << ". " << camionistas[i].nome
                  << " | Estado: " << camionistas[i].estado << "\n";
    }
    std::cout << "---------------------------------\n";
}

void MenuGestor::mostrarSucessoRegistarCamionista(std::vector<CamionistaDTO> camionistas){
    std::cout << "\nCamionista registado com sucesso!\n";
    listarCamionistas(camionistas);
}

void MenuGestor::mostrarSucessoRemoverCamionista(std::vector<CamionistaDTO> camionistas){
    std::cout << "\nCamionista removido com sucesso!\n";
    listarCamionistas(camionistas);
}

// ==================== CARGAS ====================

void MenuGestor::listarCargas(std::vector<CargaDTO> cargas){
    std::cout << "\n---- Lista de Cargas ----\n";
    for(int i = 0; i < cargas.size(); i++){
        std::cout << i+1 << ". Peso: " << cargas[i].peso
                  << " kg | Estado: " << cargas[i].estado
                  << " | Destino: " << cargas[i].nomeDestino << "\n";
    }
}

float MenuGestor::pedirPesoCarga(){
    while(true){
        std::cout << "\nIntroduz o peso da carga (Kg) ou -1 para voltar: ";
        float peso;
        std::cin >> peso;

        if(std::cin.fail()){
            // fail() — a leitura falhou (ex: "abc" nao e um float)
            //           o "abc\n" continua no buffer intacto
            std::cin.clear();
            // clear() — desbloqueia o cin para aceitar leituras futuras
            //            NAO descarta nada — o "abc\n" ainda esta no buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // ignore() — descarta tudo no buffer ate ao '\n' inclusive
            std::cout << "Erro: introduza um numero.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // cin >> consumiu os digitos e meteu-os em peso
        // no buffer ficou apenas o '\n' do Enter
        // ignore() descarta esse '\n' para evitar interferir com leituras futuras
        return peso;
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

int MenuGestor::pedirSelecaoCarga(std::vector<CargaDTO> cargas){
    listarCargas(cargas);
    std::cout << "Introduz o indice da carga a eliminar: ";
    int indice;
    std::cin >> indice;
    return indice-1;
}

void MenuGestor::mostrarSucessoRegistarCarga(std::vector<CargaDTO> cargas){
    std::cout << "\nCarga registada com sucesso!\n";
    listarCargas(cargas);
}

void MenuGestor::mostrarSucessoEliminarCarga(std::vector<CargaDTO> cargas){
    std::cout << "\nCarga eliminada com sucesso!\n";
    listarCargas(cargas);
}

// ==================== ROTAS ====================

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

// ==================== GERAL ====================

bool MenuGestor::pedirConfirmacao(){
    std::cout << "\nTem a certeza? (s/n): ";
    char resposta;
    std::cin >> resposta;
    return resposta == 's' || resposta == 'S';
}

void MenuGestor::mostrarErro(std::string mensagem){
    std::cout << "\nErro: " << mensagem << "\n";
}

// Mensagem de sucesso apos atribuicao
void MenuGestor::mostrarSucessoAtribuicao(std::string nomeCamionista, std::string matricula){
    std::cout << "\nAtribuicao realizada com sucesso!\n";
    std::cout << "Camionista " << nomeCamionista << " esta agora atribuido ao camiao " << matricula << ".\n";
}

void MenuGestor::visualizarCadastros(std::vector<CamiaoDTO> camioes, std::vector<CamionistaDTO> camionistas, std::vector<CargaDTO> cargas){
    if(camionistas.empty()){
        std::cout << "\nNao existem camionistas registados.\n";
    } else {
        listarCamionistas(camionistas);
    }

    if(camioes.empty()){
        std::cout << "\nNao existem camioes registados.\n";
    } else {
        listarCamioes(camioes);
    }

    if(cargas.empty()){
        std::cout << "\nNao existem cargas registadas.\n";
    } else {
        listarCargas(cargas);
    }
}