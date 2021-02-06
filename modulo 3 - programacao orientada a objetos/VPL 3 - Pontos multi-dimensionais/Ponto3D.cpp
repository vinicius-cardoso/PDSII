#include "Ponto3D.hpp"

std::string Ponto3D::to_string() const{
    return "(" + std::to_string(this->_x) + "," + std::to_string(this->_y) + "," + std::to_string(this->_z) + ")";
}

double Ponto3D::distancia(Ponto *p) const{
    Ponto3D* p3D = (Ponto3D*) p;
    double x = p3D->getX() - this->getX(); 
    double y = p3D->getY() - this->getY(); 
    double z = p3D->getZ() - this->getZ();

    return sqrt(x*x + y*y + z*z);  
}