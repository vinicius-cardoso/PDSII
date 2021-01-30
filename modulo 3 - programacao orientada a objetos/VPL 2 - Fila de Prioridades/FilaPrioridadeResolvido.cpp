#include "FilaPrioridade.hpp"

FilaPrioridade::FilaPrioridade() {}

void FilaPrioridade::inserir(int prioridade, int dado) {
  // fila está vazia -> novo nó é a cabeça
  if (this->cabeca == nullptr) {
    this->cabeca = new No(prioridade, dado, nullptr);
    this->tamanho++;
    return;
  }

  // novo nó é mais pioritário que a cabeça
  if (prioridade < this->cabeca->getPrioridade()) {
    No* antigaCabeca = this->cabeca;
    this->cabeca = new No(prioridade, dado, antigaCabeca);
    this->tamanho++;
    return;
  }

  // encontra o lugar do nó na fila
  No* atual = this->cabeca;
  for (int i = 0; i < this->tamanho; ++i) {
    if (
      prioridade >= atual->getPrioridade() &&
      (
        atual->getProximo() == nullptr ||
        prioridade < atual->getProximo()->getPrioridade()
      )
    ) {
      atual->setProximo(new No(prioridade, dado, atual->getProximo()));
      this->tamanho++;
      return;
    }
    atual = atual->getProximo();
  }
}

int FilaPrioridade::remover() {
  No* novaCabeca = this->cabeca->getProximo();
  int dado = this->cabeca->getDado();
  delete this->cabeca;
  this->cabeca = novaCabeca;
  this->tamanho--;
  return dado;
}

int FilaPrioridade::estaVazio() {
  if (this->tamanho == 0) {
    return true;
  }
  return false;
}

unsigned FilaPrioridade::getTamanho() {
  return this->tamanho;
}

int FilaPrioridade::getMeio() {
  int indiceMeio = this->tamanho / 2;
  No* atual = this->cabeca;
  for (int i = 0; i < indiceMeio; ++i) {
    atual = atual->getProximo();
  }
  return atual->getDado();
}

int FilaPrioridade::getUltimo() {
  No* atual = this->cabeca;
  for (int i = 0; i < this->tamanho - 1; ++i) {
    atual = atual->getProximo();
  }
  return atual->getDado();
}

void FilaPrioridade::furaFila(int dado) {
  int prioridade = this->cabeca->getPrioridade() - 1;
  this->inserir(prioridade, dado);
}

void FilaPrioridade::print() {
  No* atual = this->cabeca;
  for (int i = 0; i < this->tamanho; ++i) {
    std::cout << atual->getDado() << " ";
    atual = atual->getProximo();
  }
}
