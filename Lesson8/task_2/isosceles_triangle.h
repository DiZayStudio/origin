#pragma once

#include "triangle.h"
#include "MyException.h"

//�������������� �����������
class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(int A, int B,int C, int a, int b,int c);
    bool check() override;
};
