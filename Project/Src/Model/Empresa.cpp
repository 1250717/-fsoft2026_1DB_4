#include "..\..\Headers\Model\Empresa.h"

// inicializa o atributo static a nullptr — ainda nao existe nenhuma instancia
Empresa* Empresa::instance = nullptr;

/*O construtor só corre quando criamos um objeto. 
O instance precisa de existir antes de qualquer objeto ser criado — 
é ele que diz se já existe um objeto ou não. 
Se inicializassemos dentro do construtor:

Empresa::Empresa(...){
    instance = nullptr; // resetava o instance cada vez que criassemos um objeto
    //dava para criar multiplas nao queremos isso
}*/

Empresa::Empresa(std::string nif, std::string nome) {
    this->nif = nif;
    this->nome = nome;
    this->coordenadaX = 0.0f;
    this->coordenadaY = 0.0f;
}

Empresa* Empresa::getInstance(std::string nif, std::string nome) {
    if(instance == nullptr){
        // primeira vez — cria a unica instancia
        // nao podemos usar: Empresa e(nif, nome);
        // porque é criado na stack — quando getInstance() termina é destruido
        // o instance ficava a apontar para memoria invalida
        // quando o service tentasse usar, dava asneira
        // com new — o objeto é criado na heap e nao é destruido quando a funcao termina
        instance = new Empresa(nif, nome);
        //nunca mais volta aqui
        //vai abaixo ao return instance
    }
    // ja existe — devolve a mesma, ignora os parametros
    return instance;
}

float Empresa::getCoordenadaX() {
    return this->coordenadaX;
}

float Empresa::getCoordenadaY() {
    return this->coordenadaY;
}

CamiaoContainer& Empresa::getCamiaoContainer() {
    return this->camiaoContainer;
}

CamionistaContainer& Empresa::getCamionistaContainer() {
    return this->camionistaContainer;
}

CargaContainer& Empresa::getCargaContainer() {
    return this->cargaContainer;
}

RotaContainer& Empresa::getRotaContainer() {
    return this->rotaContainer;
}

LocalidadeContainer& Empresa::getLocalidadeContainer() {
    return this->localidadeContainer;
}