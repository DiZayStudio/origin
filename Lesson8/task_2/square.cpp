#include <iostream>
#include "square.h"

//�������
Square::Square(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
    this->name_ = "�������";
    std::cout << name_ << " (������� " << a << ", " << b << ", " << c << ", " << d << "; ";
    std::cout << "���� " << A << ", " << B << ", " << C << ", " << D << ") ";
    if (a != b && b != c && c != d && A != 90 && B != 90 && C != 90 && D != 90) throw MyException(" �� ��� ������� ����� ��� �� ��� ���� ����� 90");
    std::cout << "������." << std::endl;
}
bool Square::check() {
    if (a_ == b_ && b_ == c_ && c_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
    else return false;
}


