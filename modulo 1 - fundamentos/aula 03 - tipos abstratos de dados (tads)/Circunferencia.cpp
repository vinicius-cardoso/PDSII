#include "Circunferencia.hpp"
#include <cmath>
#define PI 3.14

Circunferencia::Circunferencia(double xc, double yc, double raio){
    _xc = xc;
    _yc = yc;
    _raio = raio;
}

double Circunferencia::calcularArea(){
    return PI * pow(_raio, 2);
}

bool Circunferencia::possuiIntersecao(struct Circunferencia *c){
    double soma_raios = _raio + c->_raio;
    double dif_x = pow((c->_xc - _xc), 2);
    double dif_y = pow((c->_yc - _yc), 2);
    double dist = sqrt(dif_x + dif_y);

    return (soma_raios >= dist);
}