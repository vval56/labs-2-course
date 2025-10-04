#ifndef CIRCLE_H 
#define CIRCLE_H

#include <iostream>
#include "shapes.h"

class Circle : public Shape {
public:
    explicit Circle(const double * parametrs) : radius_(parametrs[0]) {}
    double Square() const override;
    void Parametrs() const override;
    std::string Name() const override;
private:
    double radius_;
    double square_;
    std::string name = "Круг";
};

#endif