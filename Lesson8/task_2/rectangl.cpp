#include <iostream>
#include "rectangl.h"

//прямоугольник
Rectangl::Rectangl(int A, int B, int C, int D, int a, int b, int c, int d) :Parallelogram(A, B, C, D, a, b, c, d) {
    
    this->name_ = "Прямоугольник";
    std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; ";
    std::cout << "углы " << A << ", " << B << ", " << C << ", " << D << ") ";
    if (a != c || b != d || A != 90 || B != 90 || C != 90 || D != 90) throw MyException("cтороны a,c и b,d попарно не равны или все углы не равны 90");
    std::cout << "создан." << std::endl;
}
bool Rectangl::check() {
    if (a_ == c_ && b_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
    else return false;
}
