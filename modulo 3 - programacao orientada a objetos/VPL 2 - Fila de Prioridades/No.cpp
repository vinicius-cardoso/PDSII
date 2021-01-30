#include "No.hpp"
#include "FilaPrioridade.hpp"

No::No(int prioridade, int dado, No* proximo){
    this->_prioridade = prioridade;
    this->_dado = dado;
    this->_proximo = proximo;
}

void No::setProximo(No *next){
    this->_proximo = next;
}

No* No::getProximo(){
    return _proximo;
}

int No::getDado(){
    return _dado;
}

void No::setDado(int dado){
    this->_dado = dado;
}

int No::getPrioridade(){
    return _prioridade;
}

void No::setPrioridade(int prioridade){
    this->_prioridade = prioridade;
}