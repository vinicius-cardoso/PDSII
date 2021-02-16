#include <iostream>
#include "Point.h"

std::ostream &operator << (std::ostream &out, const Point &p){
    return out << "(" << p.x << ", " << p.y << ")";
}

std::istream &operator >> (std::istream &in, Point &p){
    in >> p.x >> p.y;

    return in;
}

Point Point::operator + (const Point &p){
    double X = this->x + p.getX();
    double Y = this->y + p.getY();

    Point ponto = Point(X, Y);

    return ponto; 
}

Point &Point::operator += (const Point &p){
    double X = this->x + p.getX();
    double Y = this->y + p.getY();

    this->x = X;
    this->y = Y;

    return *this;
}