#include <iostream>
#include "equilateral_triangle.h"

//�������������� �����������

Equilateral_triangle::Equilateral_triangle(int a) : Triangle(60, 60, 60, a, a, a) {
    this->name_ = "�������������� �����������";
}
bool Equilateral_triangle::check() {
    if (a_ == b_ && b_ == c_ && A_ == B_ && B_ == C_) return true;
    else return false;
}
