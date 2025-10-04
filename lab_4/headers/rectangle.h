#ifndef RECTANGLE_H 
#define RECTANGLE_H

#include <iostream>
#include "shapes.h"

class Rectangle : public Shape {
public:
    explicit Rectangle(double * parametrs);
    double Square() const override;
    void Parametrs() const override;
    std::string Name() const override;
private:
    double side1_;
    double side2_;
    double square_;
    std::string name;
};

#endif