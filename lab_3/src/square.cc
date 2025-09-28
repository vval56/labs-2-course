#include "../headers/circle.h"
#include "../headers/triangle.h"
#include "../headers/square.h"

bool Square::intersect_with(const Shape* other) const { 
    return other->intersect_with(this);
}

bool Square::intersect_with(const Circle* circle) const {
    std::cout << "Квадрат пресекается с кругом" << std::endl;
    return false;
}

bool Square::intersect_with(const Triangle* triangle) const {
    std::cout << "Квадрат пересекается с треугольником" << std::endl;
    return false;
}

bool Square::intersect_with(const Square* square) const {
    std::cout << "Квадрат пересекается с квадратом" << std::endl;
    return false;
}