#include "..\..\Headers\Repository\GeneralRepository.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "..\..\Headers\Model\Empresa.h"

using namespace std;

GeneralRepository::GeneralRepository(){
    // vai buscar a instancia da empresa ja criada no main
    Empresa* empresa = Empresa::getInstance();
    this->camiaoContainer = &empresa->getCamiaoContainer();
    this->camionistaContainer = &empresa->getCamionistaContainer();
    this->cargaContainer = &empresa->getCargaContainer();
    this->rotaContainer = &empresa->getRotaContainer();
    this->localidadeContainer = &empresa->getLocalidadeContainer();
}

void GeneralRepository::carregar() {
    carregarLocalidades(); //somos nos que mudamos o ficheiro txt das localidades
    //so precisamos do carregar
    carregarCargas();
    carregarCamioes();
    carregarCamionistas();
    carregarRotas();
}

void GeneralRepository::guardar() {
    guardarCargas();
    guardarCamioes();
    guardarCamionistas();
    guardarRotas();
}

void GeneralRepository::carregarCamioes(){
    ifstream ficheiro("Dados/camioes.txt");
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
    ifstream ficheiro("Dados/camionistas.txt");
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
    ifstream ficheiro("Dados/cargas.txt");
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
            } else if(campo == 0){
                pesoStr += linha[i];
            } else if(campo == 1){
                estado += linha[i];
            } else if(campo == 2){
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
    ifstream ficheiro("Dados/localidades.txt");
    if(!ficheiro.is_open()){
        cout << "Erro ao abrir localidades.txt\n";
        return;
    }
    /*Um ifstream é basicamente um
    objeto que pede ao sistema operativo 
    para abrir um ficheiro e recebe em troca um 
    identificador numérico. A partir daí, em vez de ir ao disco 
    byte a byte (o que seria lento), carrega blocos grandes para um buffer em RAM. 
    Quando fazes getline, ele lê desse buffer até encontrar um '\n', 
    devolve a linha, e quando o buffer esgota vai buscar mais ao disco. */
    string linha;
    while(getline(ficheiro, linha)){
        string nome = "";
        string coordxStr = "";
        string coordyStr = "";
        int campo = 0;

        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == ','){
                campo++;
            } else if(campo == 0){
                nome += linha[i];
            } else if(campo == 1){
                coordxStr += linha[i];
            } else if(campo == 2){
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

void GeneralRepository::guardarRotas() {
    ofstream ficheiro("Dados/rotas.txt");
    if (!ficheiro.is_open()) return;

    vector<Rota>& lista = rotaContainer->getTodos();
    for (int i = 0; i < lista.size(); i++) {
        ficheiro << lista[i].getIdRota() << ","
                 << lista[i].getNomeCamionista() << ","
                 << lista[i].getMatriculaCamiao() << ","
                 << lista[i].getDistanciaTotal();

        vector<string>& destinos = lista[i].getDestinos();
        for (int j = 0; j < destinos.size(); j++) {
            ficheiro << "," << destinos[j];
        }
        ficheiro << "\n";
    }
    ficheiro.close();
}

void GeneralRepository::carregarRotas(){
    ifstream ficheiro("Dados/rotas.txt");
    if(!ficheiro.is_open()){
        cout << "Erro ao abrir rotas.txt\n";
        return;
    }

    string linha;
    while(getline(ficheiro, linha)){
        int campo = 0;
        string idRotaStr = "";
        string nomeCamionista = "";
        string matriculaCamiao = "";
        string distanciaTotalStr = "";
        vector<string> destinos;
        string destinoAtual = "";

        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == ','){
                if(campo >= 4 && !destinoAtual.empty()){
                    // encontrou virgula e ja estamos nos destinos (campo 4+)
                    // guarda o destino que estava a ser construido e limpa para o proximo
                    destinos.push_back(destinoAtual);
                    destinoAtual = "";
                }
                campo++;
            } else if(campo == 0){
                idRotaStr += linha[i];
            } else if(campo == 1){
                nomeCamionista += linha[i];
            } else if(campo == 2){
                matriculaCamiao += linha[i];
            } else if(campo == 3){
                distanciaTotalStr += linha[i];
            } else if(campo >= 4){
                destinoAtual += linha[i];
            }
        }

        // o ultimo destino da linha nao tem virgula a seguir
        // por isso nunca entrou no if acima — guardamos aqui manualmente
        if(!destinoAtual.empty()){
            destinos.push_back(destinoAtual);
        }

        int idRota = stoi(idRotaStr);
        float distanciaTotal = stof(distanciaTotalStr);
        Rota rota(idRota, nomeCamionista, matriculaCamiao, distanciaTotal, destinos);
        rotaContainer->guardar(rota);
    }
    ficheiro.close();
}


void GeneralRepository::guardarLocalidades() {
    ofstream ficheiro("Dados/localidades.txt");
    if (!ficheiro.is_open()) return;

    vector<Localidade>& lista = localidadeContainer->getTodos();
    for (int i = 0; i < lista.size(); i++) {
        ficheiro << lista[i].getNome() << ","
                 << lista[i].getCoordenadaX() << ","
                 << lista[i].getCoordenadaY() << "\n";
    }
    ficheiro.close();
}

void GeneralRepository::guardarCargas() {
    ofstream ficheiro("Dados/cargas.txt");
    if (!ficheiro.is_open()) return;

    vector<Carga>& lista = cargaContainer->getTodos();
    for (int i = 0; i < lista.size(); i++) {
        ficheiro << lista[i].getPeso() << ","
                 << lista[i].getEstado() << ","
                 << lista[i].getDestino()->getNome() << "\n";
    }
    ficheiro.close();
}

void GeneralRepository::guardarCamioes() {
    ofstream ficheiro("Dados/camioes.txt");
    if (!ficheiro.is_open()) return;

    vector<Camiao>& listaCamioes = camiaoContainer->getTodos();
    for (int i = 0; i < listaCamioes.size(); i++) {
        ficheiro << listaCamioes[i].getMatricula() << ","
                 << listaCamioes[i].getEstado() << ","
                 << listaCamioes[i].getCapacidadeMaxima() << ","
                 << listaCamioes[i].getCapacidadeDisponivel() << ",";
        
        if (listaCamioes[i].getCamionista() != nullptr) {
            ficheiro << listaCamioes[i].getCamionista()->getNome();
        }
        
        vector<Carga*>& listaCargas = listaCamioes[i].getCargas();
        for (int j = 0; j < listaCargas.size(); j++) {
            ficheiro << "," << listaCargas[j]->getPeso()
                     << "," << listaCargas[j]->getEstado()
                     << "," << listaCargas[j]->getDestino()->getNome();
        }
        ficheiro << "\n";
    }
    ficheiro.close();
}

void GeneralRepository::guardarCamionistas() {
    ofstream ficheiro("Dados/camionistas.txt");
    if (!ficheiro.is_open()) return;

    vector<Camionista>& lista = camionistaContainer->getTodos();
    for (int i = 0; i < lista.size(); i++) {
        ficheiro << lista[i].getNome() << ","
                 << lista[i].getEstado() << ",";
        
        if (lista[i].getCamiao() != nullptr) {
            ficheiro << lista[i].getCamiao()->getMatricula();
        }
        ficheiro << "\n";
    }
    ficheiro.close();
}
