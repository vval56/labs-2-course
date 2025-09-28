#include "../headers/circle.h"
#include "../headers/triangle.h"
#include "../headers/square.h"

bool Triangle::intersect_with(const Shape* other) const { 
    return other->intersect_with(this);
}

bool Triangle::intersect_with(const Circle* circle) const {
    std::cout << "Треугольник пресекается с кругом" << std::endl;
    return false;
}

bool Triangle::intersect_with(const Triangle* triangle) const {
    std::cout << "Треугольник пересекается с треугольником" << std::endl;
    return false;
}

bool Triangle::intersect_with(const Square* square) const {
    std::cout << "Треугольник пересекается с квадратом" << std::endl;
    return false;
}