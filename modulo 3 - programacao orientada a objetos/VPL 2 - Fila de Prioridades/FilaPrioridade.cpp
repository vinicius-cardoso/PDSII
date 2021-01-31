#include "FilaPrioridade.hpp"

FilaPrioridade::FilaPrioridade() {}

void FilaPrioridade::inserir(int prioridade, int dado){
    if(this->cabeca == nullptr){
        this->cabeca = new No(prioridade, dado, nullptr);
        this->tamanho++;
    }
    else if(prioridade < this->cabeca->getPrioridade()){
        this->cabeca = new No(prioridade, dado, this->cabeca);
        this->tamanho++;
    }

    No* cabecaAtual = this->cabeca;

    for(int i = 0; i <= this->tamanho; i++){
        if(prioridade >= cabecaAtual->getPrioridade() && (cabecaAtual->getProximo() == nullptr || prioridade < cabecaAtual->getProximo()->getPrioridade())){
            cabecaAtual->setProximo(new No(prioridade, dado, cabecaAtual->getProximo()));
            this->tamanho++;
        }

        cabecaAtual = cabecaAtual->getProximo();
    }
}

int FilaPrioridade::remover(){
    No* proximaCabeca = this->cabeca->getProximo();
    delete this->cabeca;
    this->cabeca = proximaCabeca;

    int dadoPrimeiroNo = this->cabeca->getDado();
    this->tamanho--;
    
    return dadoPrimeiroNo;
}

int FilaPrioridade::estaVazio(){
    if(this->tamanho == 0){
        return true;
    }
    else{
        return false;
    }
}

unsigned FilaPrioridade::getTamanho(){
    return tamanho;
}

int FilaPrioridade::getMeio(){
    int meio; 

    if(this->tamanho % 2 == 0){
        meio = this->tamanho / 2;
    }
    else{
        meio = (this->tamanho / 2) + 1;
    }
    
    No* elementoMeio = this->cabeca;

    for(int i = 0; i <= meio; i++){
        elementoMeio = elementoMeio->getProximo();
    }

    return elementoMeio->getDado();
}

int FilaPrioridade::getUltimo(){
    No* ultimo = this->cabeca;

    for(int i = 0; i <= this->tamanho - 1; i++){
        ultimo = ultimo->getProximo();
    }

    return ultimo->getDado();
}

void FilaPrioridade::furaFila(int dado){
    int prioridade = this->cabeca->getPrioridade() - 1;
    this->inserir(prioridade, dado);
}

void FilaPrioridade::print(){
    No* fila = this->cabeca;

    for(int i = 0; i <= this->tamanho; i++){
        cout << fila->getDado() << " ";
        fila = fila->getProximo();
    }
}