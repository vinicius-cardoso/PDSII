#include "Estudante.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    Estudante estudante[10];
    Estudante temp;
        
    for(int i = 0; i < 10; i++){
        cin >> estudante[i].matricula;
        cin >> estudante[i].nome;

        for(int j = 0; j < 5; j++){
            cin >> estudante[i].notas[j];
        }
    }

    // Precisão de 2 casas decimais
    cout << fixed << showpoint;
    cout << setprecision(2);
    
    // Selection Sort
    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            if((estudante[i].calcularRSG() > estudante[j].calcularRSG()) || ((estudante[i].calcularRSG() == estudante[j].calcularRSG()) && (estudante[i].matricula < estudante[j].matricula))){
                temp = estudante[i];
                estudante[i] = estudante[j];
                estudante[j] = temp;
            }
        }
    }

    // Primeiro
    cout << estudante[9].matricula << " ";
    cout << estudante[9].nome << " ";
    cout << estudante[9].calcularRSG() << endl;

    // Segundo
    cout << estudante[8].matricula << " ";
    cout << estudante[8].nome << " ";
    cout << estudante[8].calcularRSG() << endl;

    // Terceiro
    cout << estudante[7].matricula << " ";
    cout << estudante[7].nome << " ";
    cout << estudante[7].calcularRSG() << endl;

    return 0;
}