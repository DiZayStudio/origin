#pragma once

#include "triangle.h"
#include "MyException.h"

//равносторонний треугольник
class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int A, int B, int C, int a, int b, int c);
    bool check() override;
};