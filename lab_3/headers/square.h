#ifndef SQUARE_H 
#define SQUARE_H

#include <iostream>
#include "shapes.h"

class Square : public Shape {
public:
    bool intersect_with(const Shape* other) const override;
    bool intersect_with(const Circle* circle) const override;
    bool intersect_with(const Triangle* triangle) const override;
    bool intersect_with(const Square* square) const override;
};

#endif