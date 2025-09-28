#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class Circle;
class Triangle;
class Square;

class Shape {
public:
    virtual ~Shape() = default;

    virtual bool intersect_with(const Shape* other) const = 0;
    virtual bool intersect_with(const Circle* circle) const = 0;
    virtual bool intersect_with(const Triangle* triangle) const = 0;
    virtual bool intersect_with(const Square* square) const = 0;
};

#endif