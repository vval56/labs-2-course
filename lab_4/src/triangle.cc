#include "../headers/triangle.h"

double Triangle::Square() const {
    return side1_ * side2_ / 2;
}

Triangle::Triangle(double * parametrs) : side1_(parametrs[0]), side2_(parametrs[1]), name("Тругольник") {
}

void Triangle::Parametrs() const {
    std::cout << "катеты : " << side1_ << ", " << side2_ << "\n" ;
}

std::string Triangle::Name() const {
    return name;
}