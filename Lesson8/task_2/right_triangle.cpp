#include <iostream>
#include "right_triangle.h"

//������������� �����������
Right_triangle::Right_triangle(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
    this->name_ = "������������� ����������� ";

    
    std::cout << name_ << " (������� " << a << ", " << b << ", " << c << "; ";
    std::cout << "���� " << A << ", " << B << ", " << C << ") ";
    if (C != 90) throw MyException("���� � �� ����� 90");
    std::cout << "������." << std::endl; 
}
bool Right_triangle::check() {
    if (C_ == 90) return true;
    else return false;
}