#include <iostream>
#include "isosceles_triangle.h"

//равнобедренный треугольник
    Isosceles_triangle::Isosceles_triangle(int A, int B,int C, int a, int b, int c) : Triangle(A, B, C, a, b, C) {
        this->name_ = "–авнобедренный треугольник";
        std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << "; ";
        std::cout << "углы " << A << ", " << B << ", " << C << ") ";
        if (a != c || A != C) throw MyException(" стороны a и c не равны или углы A и C не равны");
        std::cout << "создан." << std::endl;
    }
    bool Isosceles_triangle::check() {
        if (a_ == c_ && A_ == C_) return true;
        else return false;
    }