#pragma once

#include "triangle.h"

//�������������� �����������
class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int a);
    bool check() override;
};