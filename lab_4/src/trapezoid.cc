#include "../headers/trapezoid.h"

double Trapezoid::square() const {
    return side1_ * side2_;
}

void Trapezoid::parametrs() const {
    std::cout << "стороны : " << side1_ << ", " << side2_ << ", высота : "<< height_ << "\n" ;
}

std::string Trapezoid::name() const {
    return name_;
}