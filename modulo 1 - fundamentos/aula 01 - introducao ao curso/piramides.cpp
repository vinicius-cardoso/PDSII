// Escreva um programa que lê um número inteiro e escreve como saída uma pirâmide formada por '*' que possui altura igual ao valor lido.

#include <iostream>

using namespace std;

int main ()
{
    int i, j, altura;

    cin >> altura;

    for (i = 0; i <= altura; i++)
    {
        for (j = 0; j < i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for (i = (altura - 1); i >= 0; i--)
    {
        for (j = i; j > 0; j--)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}