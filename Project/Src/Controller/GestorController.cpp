#include "Project\Headers\Controller\GestorController.h"
#include <iostream>

using namespace std;

GestorController::GestorController(CamiaoContainer *camiaoContainer,
                                   CamionistaContainer *camionistaContainer,
                                   CargaContainer *cargaContainer,
                                   RotaContainer *rotaContainer) {
    this->camiaoContainer = camiaoContainer;
    this->camionistaContainer = camionistaContainer;
    this->cargaContainer = cargaContainer;
    this->rotaContainer = rotaContainer;
}

void GestorController::registarCamiao(string matricula, float capacidade) {
    if (camiaoContainer->validarMatricula(matricula) != nullptr) {
        cout << "Erro: ja existe um camiao com a matricula " << matricula << "!\n";
        return;
    }
    Camiao camiao(matricula, capacidade);
    camiaoContainer->guardar(camiao);
    cout << "Camiao registado com sucesso!\n";
    for (Camiao &c : camiaoContainer->getTodos()) {
        cout << "- " << c.getMatricula()
             << " | Capacidade: " << c.getCapacidadeMaxima()
             << " | Estado: " << c.getEstado() << "\n";
    }
}

void GestorController::registarCamionista(string nome) {
    if (camionistaContainer->validarNome(nome) != nullptr) {
        cout << "Erro: ja existe um camionista com o nome " << nome << "!\n";
        return;
    }
    Camionista camionista(nome);
    camionistaContainer->guardar(camionista);
    cout << "Camionista registado com sucesso!\n";
    for (Camionista &c : camionistaContainer->getTodos()) {
        cout << "- " << c.getNome()
             << " | Estado: " << c.getEstado() << "\n";
    }
}

void GestorController::registarCarga(float peso, string destino) {
    if (peso <= 0 || destino.empty()) {
        cout << "Erro: dados invalidos!\n";
        return;
    }
    Localidade *local = new Localidade(destino, 0.0, 0.0);
    Carga carga(peso, local);
    cargaContainer->guardar(carga);
    cout << "Carga registada com sucesso!\n";
    for (Carga &c : cargaContainer->getTodos()) {
        cout << "- Peso: " << c.getPeso()
             << " | Destino: " << c.getDestino()->getNome()
             << " | Estado: " << c.getEstado() << "\n";
    }
}

void GestorController::listarTodos() {
    cout << "\n=== Camioes ===\n";
    if (camiaoContainer->getTodos().empty()) {
        cout << "Nao ha camioes registados.\n";
    } else {
        for (Camiao &c : camiaoContainer->getTodos()) {
            cout << "- " << c.getMatricula()
                 << " | Capacidade: " << c.getCapacidadeMaxima()
                 << " | Estado: " << c.getEstado() << "\n";
        }
    }

    cout << "\n=== Camionistas ===\n";
    if (camionistaContainer->getTodos().empty()) {
        cout << "Nao ha camionistas registados.\n";
    } else {
        for (Camionista &c : camionistaContainer->getTodos()) {
            cout << "- " << c.getNome()
                 << " | Estado: " << c.getEstado() << "\n";
        }
    }

    cout << "\n=== Cargas ===\n";
    if (cargaContainer->getTodos().empty()) {
        cout << "Nao ha cargas registadas.\n";
    } else {
        int i = 0;
        for (Carga &c : cargaContainer->getTodos()) {
            cout << "[" << i++ << "] Peso: " << c.getPeso()
                 << " | Destino: " << c.getDestino()->getNome()
                 << " | Estado: " << c.getEstado() << "\n";
        }
    }
}

void GestorController::atribuirCamionista(string matriculaCamiao, string nomeCamionista) {
    Camiao *camiao = camiaoContainer->procurar(matriculaCamiao);
    if (camiao == nullptr) {
        cout << "Erro: camiao nao encontrado!\n";
        return;
    }
    if (camiao->getEstado() != "Disponivel") {
        cout << "Erro: camiao nao esta disponivel!\n";
        return;
    }

    Camionista *camionista = camionistaContainer->procurar(nomeCamionista);
    if (camionista == nullptr) {
        cout << "Erro: camionista nao encontrado!\n";
        return;
    }
    if (camionista->getEstado() != "Disponivel") {
        cout << "Erro: camionista nao esta disponivel!\n";
        return;
    }

    camiao->setCamionista(camionista);
    camionista->setCamiao(camiao);
    camiao->setEstado("Em Transito");
    camionista->setEstado("Em Transito");

    cout << "Camionista " << nomeCamionista
         << " atribuido ao camiao " << matriculaCamiao << " com sucesso!\n";

    cout << "\n=== Associacoes ===\n";
    for (Camiao &c : camiaoContainer->getTodos()) {
        if (c.getCamionista() != nullptr) {
            cout << "- Camiao: " << c.getMatricula()
                 << " | Camionista: " << c.getCamionista()->getNome() << "\n";
        }
    }
}

void GestorController::removerCamionista(string nome) {
    Camionista *camionista = camionistaContainer->procurar(nome);
    if (camionista == nullptr) {
        cout << "Erro: camionista nao encontrado!\n";
        return;
    }

    Camiao *camiao = camionista->getCamiao();
    if (camiao != nullptr) {
        if (camiao->temCargasPorEstado("Atribuida") ||
            camiao->temCargasPorEstado("Em Transito")) {
            cout << "Erro: nao e possivel remover o camionista com cargas pendentes!\n";
            return;
        }
        camiao->setCamionista(nullptr);
        camiao->setEstado("Disponivel");
        camionista->setCamiao(nullptr);
    }

    camionistaContainer->remover(nome);
    cout << "Camionista " << nome << " removido com sucesso!\n";
}

void GestorController::removerCarga(int indice) {
    Carga *carga = cargaContainer->procurar(indice);
    if (carga == nullptr) {
        cout << "Erro: carga nao encontrada!\n";
        return;
    }
    if (carga->getEstado() == "Em Transito") {
        cout << "Erro: nao e possivel remover uma carga em transito!\n";
        return;
    }
    if (carga->getEstado() == "Atribuida") {
        for (Camiao &c : camiaoContainer->getTodos()) {
            c.removerCarga(carga);
        }
    }
    cargaContainer->remover(indice);
    cout << "Carga removida com sucesso!\n";
}

void GestorController::removerCamiao(string matricula) {
    Camiao *camiao = camiaoContainer->procurar(matricula);
    if (camiao == nullptr) {
        cout << "Erro: camiao nao encontrado!\n";
        return;
    }
    if (camiao->temCargas()) {
        cout << "Erro: nao e possivel remover um camiao com cargas pendentes!\n";
        return;
    }

    Camionista *camionista = camiao->getCamionista();
    if (camionista != nullptr) {
        camionista->setCamiao(nullptr);
        camionista->setEstado("Disponivel");
        camiao->setCamionista(nullptr);
    }

    camiaoContainer->remover(matricula);
    cout << "Camiao " << matricula << " removido com sucesso!\n";
}

void GestorController::listarRotasConcluidas() {
    vector<Rota> &rotas = rotaContainer->getTodos();
    if (rotas.empty()) {
        cout << "Nao ha rotas concluidas registadas.\n";
        return;
    }
    cout << "\n=== Rotas Concluidas ===\n";
    for (Rota &r : rotas) {
        cout << "- Rota ID: " << r.getIdRota()
             << " | Camionista: " << r.getNomeCamionista()
             << " | Camiao: " << r.getMatriculaCamiao()
             << " | Distancia Total: " << r.getDistanciaTotal() << " km\n";
        cout << "  Cargas (ordem FIFO):\n";
        for (Carga &c : r.getCargas()) {
            cout << "    -> " << c.getDestino()->getNome()
                 << " | Peso: " << c.getPeso() << "\n";
        }
    }
}