#include "FilaPrioridade.hpp"

FilaPrioridade::FilaPrioridade() {}

void FilaPrioridade::inserir(int prioridade, int dado){
    if(this->cabeca == nullptr){
        this->cabeca = new No(prioridade, dado, nullptr);
        this->tamanho++;

        return;
    }
    else if(prioridade < this->cabeca->getPrioridade()){
        this->cabeca = new No(prioridade, dado, this->cabeca);
        this->tamanho++;

        return;
    }

    No* cabecaAtual = this->cabeca;

    for(int i = 0; i < this->tamanho; ++i){
        if(prioridade >= cabecaAtual->getPrioridade() && (cabecaAtual->getProximo() == nullptr || prioridade < cabecaAtual->getProximo()->getPrioridade())){
            cabecaAtual->setProximo(new No(prioridade, dado, cabecaAtual->getProximo()));
            this->tamanho++;

            return;
        }

        cabecaAtual = cabecaAtual->getProximo();
    }
}

int FilaPrioridade::remover(){
    No* proximaCabeca = this->cabeca->getProximo();
    int dadoPrimeiroNo = this->cabeca->getDado();
    
    delete this->cabeca;
    this->cabeca = proximaCabeca;
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

    meio = this->tamanho / 2;
    
    No* elementoMeio = this->cabeca;

    for(int i = 0; i < meio; ++i){
        elementoMeio = elementoMeio->getProximo();
    }

    return elementoMeio->getDado();
}

int FilaPrioridade::getUltimo(){
    No* ultimo = this->cabeca;

    for(int i = 0; i < this->tamanho - 1; ++i){
        ultimo = ultimo->getProximo();
    }

    return ultimo->getDado();
}

void FilaPrioridade::furaFila(int dado){
    int prioridade = this->cabeca->getPrioridade() - 1;
    
    this->inserir(prioridade, dado);
}

void FilaPrioridade::print(){
    No* elementoFila = this->cabeca;

    for(int i = 0; i < this->tamanho; ++i){
        cout << elementoFila->getDado() << " ";
        elementoFila = elementoFila->getProximo();
    }
}