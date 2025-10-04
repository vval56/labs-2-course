#include "../headers/rectangle.h"

double Rectangle::Square() const {
    return side1_ * side2_;
}

Rectangle::Rectangle(double * parametrs) : side1_(parametrs[0]), side2_(parametrs[1]), name("Прямоугольник") {
}

void Rectangle::Parametrs() const {
    std::cout << "стороны : " << side1_ << ", " << side2_ << "\n" ;
}

std::string Rectangle::Name() const{
    return name;
}