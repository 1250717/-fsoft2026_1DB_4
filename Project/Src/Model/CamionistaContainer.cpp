#include "..\..\Headers\Model\CamionistaContainer.h"

Camionista* CamionistaContainer::validarNome(std::string nome) {
    return procurar(nome);
}

void CamionistaContainer::guardar(Camionista camionista) {
    camionistas.push_back(camionista);
}

std::vector<Camionista>& CamionistaContainer::getTodos() {
    return camionistas;
}

std::vector<Camionista*> CamionistaContainer::getDisponiveis() {
    std::vector<Camionista*> disponiveis;
    for (int i = 0; i < (int)camionistas.size(); i++) {
        if (camionistas[i].getEstado() == "Disponivel") {
            disponiveis.push_back(&camionistas[i]);
        }
    }
    return disponiveis;
}

Camionista* CamionistaContainer::procurar(std::string nome) {
    for (int i = 0; i < (int)camionistas.size(); i++) {
        if (camionistas[i].getNome() == nome) {
            return &camionistas[i];
        }
    }
    return nullptr;
}

void CamionistaContainer::remover(std::string nome) {
    for (int i = 0; i < (int)camionistas.size(); i++) {
        if (camionistas[i].getNome() == nome) {
            camionistas.erase(camionistas.begin() + i);
            return;
        }
    }
}
// -----------------------------------------------------------------------------
// NOTAS SOBRE erase / begin / push_back
//
// push_back(valor):
//   Recebe um VALOR, não uma posição. Já sabe onde vai pôr — sempre no fim, na
//   posição 'size'. Não há ambiguidade, por isso não precisa de lhe dizer onde.
//
// begin():
//   Não devolve um índice nem um valor. Devolve um ITERADOR, que para um vector
//   é essencialmente um ponteiro (Camionista*) para o endereço do 1º elemento.
//   É um cursor que diz "estou nesta posição da memória".
//
// begin() + i:
//   Aritmética de ponteiros TIPADA. Como os elementos estão contíguos, e o
//   compilador conhece sizeof(Camionista) em tempo de compilação, faz:
//        endereço = base + i * sizeof(Camionista)
//   O 'i' está em unidades de ELEMENTO; o compilador multiplica pelo tamanho do
//   tipo sozinho. Por isso a cada i++ o endereço avança sizeof(Camionista) bytes
//   (ex.: 40), e não 1 byte.
//
// erase(posição):
//   Recebe a POSIÇÃO (iterador), não o valor nem o índice. Destrói o elemento
//   nessa posição e desloca todos os seguintes uma casa para trás → O(n).
//   Usa iterador (e não int) por consistência com toda a STL: list, set, map não
//   têm índice numérico, mas todos têm iteradores.
// -----------------------------------------------------------------------------

