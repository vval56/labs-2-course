#ifndef CIRCLE_H 
#define CIRCLE_H

#include <iostream>
#include "shapes.h"

class Circle : public Shape {
public:
    explicit Circle(double * parametrs);
    double Square() const override;
    void Parametrs() const override;
    std::string Name() const override;
private:
    double radius_;
    double square_;
    std::string name;
};

#endif