#include "../headers/rectangle.h"

double Rectangle::square() const {
    return side1_ * side2_;
}

void Rectangle::parametrs() const {
    std::cout << "стороны : " << side1_ << ", " << side2_ << "\n" ;
}

std::string Rectangle::name() const{
    return name_;
}