#include "../headers/circle.h"

constexpr double PI = 3.14159265358979323846;

double Circle::Square() const {
    return radius_ * radius_ * PI;
}

void Circle::Parametrs() const {
    std::cout << "радиус : " << radius_ << "\n" ;
}

std::string Circle::Name() const {
    return name;
}