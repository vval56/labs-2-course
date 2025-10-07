#include "../headers/circle.h"

constexpr double PI = 3.14159265358979323846;

double Circle::square() const {
    return radius_ * radius_ * PI;
}

void Circle::parametrs() const {
    std::cout << "радиус : " << radius_ << "\n" ;
}

std::string Circle::name() const {
    return name_;
}