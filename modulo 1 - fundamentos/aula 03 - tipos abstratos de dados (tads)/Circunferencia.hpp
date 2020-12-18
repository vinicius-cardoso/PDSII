#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

struct Circunferencia {
    double _xc, _yc;
    double _raio;

    //Construtor
    Circunferencia(double, double, double);

    //Metodos
    double calcularArea();
    bool possuiIntersecao(struct Circunferencia *c);
};

#endif