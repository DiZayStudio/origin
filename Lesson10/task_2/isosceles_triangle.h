#pragma once

#include "triangle.h"

//�������������� �����������
class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(int A, int B, int a, int b);
    bool check() override;
};
