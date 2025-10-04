#include "../headers/rectangle.h"

double Rectangle::Square() const {
    return side1_ * side2_;
}

void Rectangle::Parametrs() const {
    std::cout << "стороны : " << side1_ << ", " << side2_ << "\n" ;
}

std::string Rectangle::Name() const{
    return name;
}