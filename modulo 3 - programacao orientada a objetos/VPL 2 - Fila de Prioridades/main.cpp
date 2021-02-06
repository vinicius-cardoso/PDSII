#include <iostream>
#include "FilaPrioridade.hpp"

using namespace std;

int main(int argc, char** argv) {
    int prioridade;
    int dado;
 
    FilaPrioridade *fila = new FilaPrioridade();
    
    while (cin >> prioridade) {
	    cin >> dado;
        fila->inserir(prioridade, dado);   
    }
  
    fila->print();
    
    cout << endl;
    cout << "s:" << fila->getTamanho() << ", ";
    cout << "m:" << fila->getMeio() << ", ";
    cout << "u:" << fila->getUltimo() << ", ";
    cout << "r:" << fila->remover() << ", ";
    cout << "m:" << fila->getMeio() << ", ";
    cout << "u:" << fila->getUltimo() << ", ";
    
    fila->furaFila(7);
    
    cout << "m:" << fila->getMeio() << ", ";
    cout << "u:" << fila->getUltimo() << endl;
    
    fila->print();
    
    cout << endl;
    
    return 0;
}