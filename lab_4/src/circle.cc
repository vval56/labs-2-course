#include "../headers/circle.h"

Circle::Circle(double * parametrs) : radius_(parametrs[0]), name("Круг"){}

double Circle::Square() const {
    return radius_ * radius_ * 3.14;
}

void Circle::Parametrs() const {
    std::cout << "радиус : " << radius_ << "\n" ;
}

std::string Circle::Name() const {
    return name;
}