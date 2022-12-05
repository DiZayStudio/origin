#include <iostream>
#include "square.h"

//квадрат
Square::Square(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
    this->name_ = "Квадрат";
    std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; ";
    std::cout << "углы " << A << ", " << B << ", " << C << ", " << D << ") ";
    if (a != b && b != c && c != d && A != 90 && B != 90 && C != 90 && D != 90) throw MyException(" не все стороны равны или не все углы равны 90");
    std::cout << "создан." << std::endl;
}
bool Square::check() {
    if (a_ == b_ && b_ == c_ && c_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
    else return false;
}


