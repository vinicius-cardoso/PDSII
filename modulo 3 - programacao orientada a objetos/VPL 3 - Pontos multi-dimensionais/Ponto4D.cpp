#include "Ponto4D.hpp"

std::string Ponto4D::to_string() const{
    return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) + "," + std::to_string(this->_z) + "," + std::to_string(this->_w) + ")";
}

double Ponto4D::distancia(Ponto *p) const{
    Ponto4D* p4D = (Ponto4D*) p;
    double x = p4D->getX() - this->getX();
    double y = p4D->getY() - this->getY();
    double z = p4D->getZ() - this->getZ();
    double w = p4D->getW() - this->getW();

    return sqrt(x*x + y*y + z*z + w*w);
}