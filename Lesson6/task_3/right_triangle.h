#pragma once

#include "triangle.h"

//прямоугольный треугольник
class Right_triangle : public Triangle {
public:
    Right_triangle(int A, int B, int a, int b, int c);
    bool check() override;
};
