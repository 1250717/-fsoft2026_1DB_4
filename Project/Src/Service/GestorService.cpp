#include "..\..\Headers\Service\GestorService.h"
#include "..\..\Headers\Dtos\CamiaoDTO.h"
#include "..\..\Headers\Dtos\CamionistaDTO.h"
#include "..\..\Headers\Mapper\CamiaoMapper.h"
#include "..\..\Headers\Mapper\CamionistaMapper.h"
#include "..\..\Headers\Mapper\RotaMapper.h"
#include "..\..\Headers\Dtos\RotaDTO.h"
#include "..\..\Headers\Dtos\CargaDTO.h"
#include "..\..\Headers\Mapper\CargaMapper.h"
#include "..\..\Headers\Model\Empresa.h"
#include <stdexcept>

GestorService::GestorService(){
    // vai buscar a instancia da empresa ja criada no main
    Empresa* empresa = Empresa::getInstance();
    this->camiaoContainer = &empresa->getCamiaoContainer();
    this->camionistaContainer = &empresa->getCamionistaContainer();
    this->cargaContainer = &empresa->getCargaContainer();
    this->rotaContainer = &empresa->getRotaContainer();
    this->localidadeContainer = &empresa->getLocalidadeContainer();
}

// Metodo auxiliar - valida o formato da matricula portuguesa atual
// Aceita apenas: AA-00-AA (formato desde 2005)

void GestorService::registrarCamiao(std::string matricula, float capacidade){
    Camiao camiao(matricula, capacidade); // construtor do Camiao valida tudo
    camiaoContainer->guardar(camiao);
}

void GestorService::registrarCamionista(std::string nomeCamionista){
    if(nomeCamionista.empty()){
        throw std::invalid_argument("Nome nao pode estar vazio.");
    }
    if(camionistaContainer->validarNome(nomeCamionista) != nullptr){//ja existe
        throw std::invalid_argument("Camionista ja existente");
    }
    Camionista camionista(nomeCamionista);
    camionistaContainer->guardar(camionista);
}

void GestorService::registarCarga(float peso, std::string nomeDestino){
    Localidade* destino = localidadeContainer->procurar(nomeDestino);
    if(destino == nullptr){
        throw std::invalid_argument("Localidade destino nao encontrada.");
    }
    Carga carga(peso, destino);
    cargaContainer->guardar(carga);
}

std::vector<CamiaoDTO> GestorService::getTodosCamioes(){
    std::vector<Camiao>& camioes = camiaoContainer->getTodos();
    std::vector<CamiaoDTO> dtos;
    for(int i = 0; i < camioes.size(); i++){
        dtos.push_back(CamiaoMapper::toDTO(camioes[i]));
    }
    return dtos;
}

std::vector<CamionistaDTO> GestorService::getTodosCamionistas(){
    std::vector<Camionista>& camionistas = camionistaContainer->getTodos();
    std::vector<CamionistaDTO> dtos;
    for(int i = 0; i < camionistas.size(); i++){
        dtos.push_back(CamionistaMapper::toDTO(camionistas[i]));
    }
    return dtos;
}

void GestorService::removerCamiao(std::string matricula){
    Camiao* camiao = camiaoContainer->procurar(matricula);
    
    if(camiao == nullptr){
        throw std::invalid_argument("Camiao nao encontrado.");
    }
    
    if(camiao->temCargas()){
        throw std::invalid_argument("Nao e possivel remover camiao com cargas pendentes.");
    }
    
    Camionista* camionista = camiao->getCamionista();
    if(camionista != nullptr){
        camionista->setCamiao(nullptr);
        camionista->setEstado("Disponivel");
        camiao->setCamionista(nullptr);
    }

    camiaoContainer->remover(matricula);
}

std::vector<CargaDTO> GestorService::getTodasCargas(){
    std::vector<Carga>& cargas = cargaContainer->getTodos();
    std::vector<CargaDTO> dtos;
    for(int i = 0; i < cargas.size(); i++){
        dtos.push_back(CargaMapper::toDTO(cargas[i]));
    }
    return dtos;
}

std::vector<Localidade> GestorService::getTodasLocalidades(){
    return localidadeContainer->getTodos();
}

void GestorService::removerCamionista(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    
    if(camionista == nullptr){
        throw std::invalid_argument("Camionista nao encontrado.");
    }
    
    //se o camionista tiver um camiao atribuido, liberta-o
    Camiao* camiao = camionista->getCamiao();
    if(camiao != nullptr){
        if(camiao->temCargasPorEstado("Atribuida") || camiao->temCargasPorEstado("Em Transito")){
            throw std::invalid_argument("Nao e possivel remover o camionista com cargas ativas.");
        }
        camiao->setCamionista(nullptr);
        camiao->setEstado("Disponivel");
        camionista->setCamiao(nullptr);
    }
    
    camionistaContainer->remover(nomeCamionista);
}
// Devolve a lista de camionistas sem camiao atribuido
std::vector<CamionistaDTO> GestorService::getCamionistasDisponiveis(){
    // Obtem referencia ao vetor de todos os camionistas
    std::vector<Camionista>& todos = camionistaContainer->getTodos();
    std::vector<CamionistaDTO> dtos;
    
    // Filtra: so adiciona os que ainda nao tem camiao
    for(int i = 0; i < todos.size(); i++){
        if(todos[i].getCamiao() == nullptr){
            dtos.push_back(CamionistaMapper::toDTO(todos[i]));
        }
    }
    return dtos;
}
 
// Devolve a lista de camioes sem camionista atribuido
std::vector<CamiaoDTO> GestorService::getCamioesDisponiveis(){
    // Obtem referencia ao vetor de todos os camioes
    std::vector<Camiao>& todos = camiaoContainer->getTodos();
    std::vector<CamiaoDTO> dtos;
    
    // Filtra: so adiciona os que ainda nao tem camionista
    for(int i = 0; i < todos.size(); i++){
        if(todos[i].getCamionista() == nullptr){
            dtos.push_back(CamiaoMapper::toDTO(todos[i]));
        }
    }
    return dtos;
}
 
// Atribui um camionista a um camiao - associacao bidirecional
void GestorService::atribuirCamionistaACamiao(std::string nomeCamionista, std::string matricula){
    // Procurar o camionista pelo nome
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    if(camionista == nullptr){
        throw std::invalid_argument("Camionista inexistente.");
    }
    
    // Validacao: o camionista nao pode ja ter camiao
    if(camionista->getCamiao() != nullptr){
        throw std::invalid_argument("Camionista ja tem camiao atribuido.");
    }
    
    // Procurar o camiao pela matricula
    Camiao* camiao = camiaoContainer->procurar(matricula);
    if(camiao == nullptr){
        throw std::invalid_argument("Camiao inexistente.");
    }
    
    // Validacao: o camiao nao pode ja ter camionista
    if(camiao->getCamionista() != nullptr){
        throw std::invalid_argument("Camiao ja tem camionista atribuido.");
    }
    
    // Associacao bidirecional: camionista <-> camiao
    camionista->setCamiao(camiao);
    camiao->setCamionista(camionista);
    camionista->setEstado("Atribuido");
    camiao->setEstado("Atribuido");
    
}

std::vector<RotaDTO> GestorService::getTodasRotas(){
    std::vector<Rota>& rotas = rotaContainer->getTodos();
    std::vector<RotaDTO> dtos;
    for(int i = 0; i < rotas.size(); i++){
        dtos.push_back(RotaMapper::toDTO(rotas[i]));
    }
    return dtos;
}

void GestorService::eliminarCarga(int indice){
    //apenas verifica se está em transito
    Carga* carga = cargaContainer->procurar(indice);
    if(carga == nullptr){
        throw std::invalid_argument("Carga nao encontrada.");
    }
    if(carga->getEstado() == "Em Transito"){
        throw std::invalid_argument("Nao e possivel eliminar uma carga em transito.");
    }
    //se não estiver em transito não faz nada
    //o controller vai pedir confirmação
}

void GestorService::eliminarCarga(int indice, bool confirmar){
    //já confirmou
    //vai remover
    Carga* carga = cargaContainer->procurar(indice);
    if(carga == nullptr){
        throw std::invalid_argument("Carga nao encontrada.");
    }
    //se a carga estava atribuida a um camião, liberta
    if(carga->getEstado() == "Atribuida"){
        //encontra o camiao que tem a carga atribuida e atualiza a carga para disponivel
        std::vector<Camiao>& camioes = camiaoContainer->getTodos();
        for(int i = 0; i < (int)camioes.size(); i++){
            std::vector<Carga*>& cargasDoCamiao = camioes[i].getCargas();
            for(int j = 0; j < (int)cargasDoCamiao.size(); j++){
                if(cargasDoCamiao[j] == carga){
                    // encontrou o camiao que tem esta carga - liberta a capacidade
                    float novaCapacidade = camioes[i].getCapacidadeDisponivel() + carga->getPeso();
                    camioes[i].setCapacidadeDisponivel(novaCapacidade);
                    camioes[i].removerCarga(carga);
                    break;
                }
            }
        }
    }
    cargaContainer->remover(indice);
}

bool GestorService::existeCamiao(std::string matricula){
    Camiao* camiao = camiaoContainer->procurar(matricula);
    if(camiao != nullptr){
        return true; // encontrou — ja existe
    }
    return false; // nao encontrou — nao existe
}

void GestorService::verificarCamionista(std::string nomeCamionista){
    Camionista* camionista = camionistaContainer->procurar(nomeCamionista);
    if(camionista == nullptr){
        throw std::invalid_argument("Camionista inexistente.");
    }
    camionista->verificarDisponivel(); // delega para a própria classe
}

void GestorService::verificarCamiao(std::string matricula){
    if(!existeCamiao(matricula)){
        throw std::invalid_argument("Camiao inexistente.");
    }
    Camiao* camiao = camiaoContainer->procurar(matricula);
    camiao->verificarDisponivel();
}