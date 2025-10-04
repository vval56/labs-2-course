#include "../headers/trapezoid.h"

double Trapezoid::Square() const {
    return side1_ * side2_;
}

void Trapezoid::Parametrs() const {
    std::cout << "стороны : " << side1_ << ", " << side2_ << ", высота : "<< height_ << "\n" ;
}

std::string Trapezoid::Name() const {
    return name;
}