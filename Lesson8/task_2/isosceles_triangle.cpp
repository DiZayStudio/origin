#include <iostream>
#include "isosceles_triangle.h"

//�������������� �����������
    Isosceles_triangle::Isosceles_triangle(int A, int B,int C, int a, int b, int c) : Triangle(A, B, C, a, b, C) {
        this->name_ = "�������������� �����������";
        std::cout << name_ << " (������� " << a << ", " << b << ", " << c << "; ";
        std::cout << "���� " << A << ", " << B << ", " << C << ") ";
        if (a != c || A != C) throw MyException(" ������� a � c �� ����� ��� ���� A � C �� �����");
        std::cout << "������." << std::endl;
    }
    bool Isosceles_triangle::check() {
        if (a_ == c_ && A_ == C_) return true;
        else return false;
    }