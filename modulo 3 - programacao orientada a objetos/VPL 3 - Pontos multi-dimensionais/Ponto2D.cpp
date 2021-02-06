#include "Ponto2D.hpp"

std::string Ponto2D::to_string() const{
    return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) + ")";
}

double Ponto2D::distancia(Ponto *p) const{
    Ponto2D* p2D = (Ponto2D*) p;
    double x = p2D->getX() - this->getX();
    double y = p2D->getY() - this->getY();

    return sqrt(x*x + y*y);
}

void Ponto2D::converteParaPolar(){
    double x = this->_x;

    this->_x = this->distancia(new Ponto2D(0, 0));
    this->_y = atan(this->_y / x);
}