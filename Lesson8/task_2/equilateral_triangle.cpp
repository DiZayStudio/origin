#include <iostream>
#include "equilateral_triangle.h"

//равносторонний треугольник

Equilateral_triangle::Equilateral_triangle(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
    
    this->name_ = "Равносторонний треугольник";
    std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << "; ";
    std::cout << "углы " << A << ", " << B << ", " << C << ") ";
    if ((a != b || b != c) || (A != B || B != C)) throw MyException("Не все стороны равны или не все углы равны");
    std::cout << "создан.";
}
bool Equilateral_triangle::check() {
    if (a_ == b_ && b_ == c_ && A_ == B_ && B_ == C_) return true;
    else return false;
}
