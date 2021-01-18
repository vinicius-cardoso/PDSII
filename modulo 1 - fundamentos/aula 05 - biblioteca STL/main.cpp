#include "Indice.hpp"

using namespace std;

int main(){
    cout << fixed << showpoint;
    cout << setprecision(2);

    float n_palavras = 0;

    string linha, palavra;

    map<string, int> lista_palavras;
    map<string, int>::iterator it;

    while(getline(cin, linha)){
        transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
        istringstream nlinha(linha);
        
        while(getline(nlinha, palavra, " ")){
            lista_palavras[palavra]++;
            n_palavras++;
        }
    }   

    for(it = lista_palavras.begin(); it != lista_palavras.end(); it++){
        if(it->first.length() >= 3){
            cout << it->first << " " << it->second << " " << (it->second / n_palavras) << endl;
        }
    }

    return 0;
}