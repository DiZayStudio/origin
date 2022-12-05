#include <iostream>
#include "equilateral_triangle.h"

//�������������� �����������

Equilateral_triangle::Equilateral_triangle(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
    
    this->name_ = "�������������� �����������";
    std::cout << name_ << " (������� " << a << ", " << b << ", " << c << "; ";
    std::cout << "���� " << A << ", " << B << ", " << C << ") ";
    if ((a != b || b != c) || (A != B || B != C)) throw MyException("�� ��� ������� ����� ��� �� ��� ���� �����");
    std::cout << "������.";
}
bool Equilateral_triangle::check() {
    if (a_ == b_ && b_ == c_ && A_ == B_ && B_ == C_) return true;
    else return false;
}
