#include <iostream>
#include "rhomb.h"

//����
Rhomb::Rhomb(int A, int B, int C, int D, int a, int b, int c, int d) :Parallelogram(A, B, C, D, a, b, c, d) {
    
;    this->name_ = "����";
    std::cout << name_ << " (������� " << a << ", " << b << ", " << c << ", " << d << "; ";
    std::cout << "���� " << A << ", " << B << ", " << C << ", " << D << ") ";
    if (a != c || b != d || A != C || B != D) throw MyException("�� ��� ������� ����� ��� ���� A,C � B,D ������� �� �����");
    std::cout << "������." << std::endl;
}
bool Rhomb::check() {
    if (a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_) return true;
    else return false;
}