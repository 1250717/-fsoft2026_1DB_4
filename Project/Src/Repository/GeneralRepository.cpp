#include "..\..\Headers\Repository\GeneralRepository.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

GeneralRepository::GeneralRepository(
        CamionistaContainer *camionistaContainer,
        CamiaoContainer *camiaoContainer,
        CargaContainer *cargaContainer,
        RotaContainer *rotaContainer,
        LocalidadeContainer *localidadeContainer
    ){
        this->camiaoContainer = camiaoContainer;
        this->camionistaContainer = camionistaContainer;
        this->cargaContainer = cargaContainer;
        this->rotaContainer = rotaContainer;
        this->localidadeContainer = localidadeContainer;
    }

void GeneralRepository::carregar() {
    carregarLocalidades();
    carregarCargas();
    carregarCamioes();
    carregarCamionistas();
}

void GeneralRepository::guardar() {
}

void GeneralRepository::carregarCamioes(){
    ifstream ficheiro("Data/camioes.txt");
    if(!ficheiro.is_open()){
        cout << "Erro ao abrir camioes.txt\n";
        return;
    }

    string linha;
    while(getline(ficheiro, linha)){
        string matricula = "";
        string estado = "";
        string capMaxStr = "";
        string capDispStr = "";
        string nomeCamionista = "";
        vector<int> indicesCargas;
        string indiceAtual = "";
        int campo = 0;

        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == ','){
                if(campo >= 5 && !indiceAtual.empty()){
                    indicesCargas.push_back(stoi(indiceAtual));
                    indiceAtual = "";
                }
                campo++;
            } else if(campo == 0){
                matricula += linha[i];
            } else if(campo == 1){
                estado += linha[i];
            } else if(campo == 2){
                capMaxStr += linha[i];
            } else if(campo == 3){
                capDispStr += linha[i];
            } else if(campo == 4){
                nomeCamionista += linha[i];
            } else if(campo >= 5){
                indiceAtual += linha[i];
            }
        }

        if(!indiceAtual.empty()){
            indicesCargas.push_back(stoi(indiceAtual));
        }

        float capacidadeMaxima = stof(capMaxStr);
        float capacidadeDisponivel = stof(capDispStr);

        Camiao camiao(matricula, capacidadeMaxima);
        camiao.setEstado(estado);
        camiao.setCapacidadeDisponivel(capacidadeDisponivel);

        for(int i = 0; i < indicesCargas.size(); i++){
            Carga* carga = cargaContainer->procurar(indicesCargas[i]);
            if(carga != nullptr){
                camiao.adicionarCarga(carga);
            }
        }

        if(!nomeCamionista.empty()){
            Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
            if(camionista != nullptr){
                camiao.setCamionista(camionista);
            }
        }

        camiaoContainer->guardar(camiao);
    }

    ficheiro.close();
}

void GeneralRepository::carregarCamionistas(){
    ifstream ficheiro("Data/camionistas.txt");
    if(!ficheiro.is_open()){
        cout << "Erro ao abrir camionistas.txt\n";
        return;
    }

    string linha;
    while(getline(ficheiro, linha)){
        string nome = "";
        string estado = "";
        string matriculaCamiao = "";
        int campo = 0;

        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == ','){
                campo++;
            } else if(campo == 0){
                nome += linha[i];
            } else if(campo == 1){
                estado += linha[i];
            } else if(campo == 2){
                matriculaCamiao += linha[i];
            }
        }

        Camionista camionista(nome);
        camionista.setEstado(estado);

        if(!matriculaCamiao.empty()){
            Camiao* camiao = camiaoContainer->procurar(matriculaCamiao);
            if(camiao != nullptr){
                camionista.setCamiao(camiao);
            }
        }

        camionistaContainer->guardar(camionista);
    }

    ficheiro.close();
}

void GeneralRepository::carregarCargas(){
    ifstream ficheiro("Data/cargas.txt");
    if(!ficheiro.is_open()){
        cout << "Erro ao abrir cargas.txt\n";
        return;
    }

    string linha;

    while(getline(ficheiro, linha)){
        string pesoStr = "";
        string estado = "";
        string nome_destino = "";
        int campo = 0;

        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == ','){
                campo++;
            }
            else if(campo == 0){
                pesoStr += linha[i];
            }
            else if(campo == 1){
                estado += linha[i];
            }
            else if(campo == 2){
                nome_destino += linha[i];
            }
        }

        if(!nome_destino.empty()){
            float peso = stof(pesoStr);
            Localidade* localidadeDestino = localidadeContainer->procurar(nome_destino);

            if(localidadeDestino != nullptr){
                Carga carga(peso, localidadeDestino);
                carga.setEstado(estado);
                cargaContainer->guardar(carga);
            }
        }
    }

    ficheiro.close();
}

void GeneralRepository::carregarLocalidades(){
    ifstream ficheiro("Data/localidades.txt");
    if(!ficheiro.is_open()){
        cout << "Erro ao abrir localidades.txt\n";
        return;
    }
    
    string linha;
    while(getline(ficheiro, linha)){
        string nome = "";
        string coordxStr = "";
        string coordyStr = "";
        int campo = 0;

        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == ','){
                campo++;
            }
            else if(campo == 0){
                nome += linha[i];
            }
            else if(campo == 1){
                coordxStr += linha[i];
            }
            else if(campo == 2){
                coordyStr += linha[i];
            }
        }
        
        if(!nome.empty() && !coordxStr.empty() && !coordyStr.empty()){
            float coordx = stof(coordxStr);
            float coordy = stof(coordyStr);

            Localidade localidade(nome, coordx, coordy);
            localidadeContainer->guardar(localidade);
        }
    }
    ficheiro.close();
}

void GeneralRepository::carregarRotas(){
}