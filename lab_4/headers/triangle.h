#ifndef TRIANGLE_H 
#define TRIANGLE_H

#include <iostream>
#include "shapes.h"

class Triangle : public Shape {
public:
    explicit Triangle(double * parametrs);
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