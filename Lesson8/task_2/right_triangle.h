#pragma once

#include "triangle.h"
#include "MyException.h"

//прямоугольный треугольник
class Right_triangle : public Triangle {
public:
    Right_triangle(int A, int B, int C, int a, int b, int c);
    bool check() override;
};
