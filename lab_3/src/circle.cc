#include "../headers/circle.h"
#include "../headers/triangle.h"
#include "../headers/square.h"

bool Circle::intersect_with(const Shape* other) const { 
    return other->intersect_with(this);
}

bool Circle::intersect_with(const Circle* circle) const {
    std::cout << "Круг пресекается с кругом" << std::endl;
    return false;
}

bool Circle::intersect_with(const Triangle* triangle) const {
    std::cout << "Круг пересекается с треугольником" << std::endl;
    return false;
}

bool Circle::intersect_with(const Square* square) const {
    std::cout << "Круг пересекается с квадратом" << std::endl;
    return false;
}