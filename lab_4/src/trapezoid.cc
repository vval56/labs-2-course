#include "../headers/trapezoid.h"

double Trapezoid::Square() const {
    return side1_ * side2_;
}

Trapezoid::Trapezoid(double * parametrs) : side1_(parametrs[0]), side2_(parametrs[1]), height_(parametrs[2]), name("Трапеция") {
}

void Trapezoid::Parametrs() const {
    std::cout << "стороны : " << side1_ << ", " << side2_ << ", высота : "<< height_ << "\n" ;
}

std::string Trapezoid::Name() const {
    return name;
}