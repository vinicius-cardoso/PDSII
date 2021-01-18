#ifndef INDICE
#define INDICE

#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Indice {
    string palavra;
    int repeticoes;
    float porcentagem;

    Indice(string, int, float);
};

#endif