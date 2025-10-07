#include "../headers/triangle.h"

double Triangle::square() const {
    return side1_ * side2_ / 2;
}

void Triangle::parametrs() const {
    std::cout << "катеты : " << side1_ << ", " << side2_ << "\n" ;
}

std::string Triangle::name() const {
    return name_;
}