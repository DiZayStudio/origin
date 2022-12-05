#include <iostream>
#include "parallelogram.h"

//параллелограмм

Parallelogram::Parallelogram(int A, int B, int C, int D, int a, int b, int c, int d) :Quadrangle(A, B, C, D, a, b, c, d) {
    this->name_ = "Параллелограмм"; 
    std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; ";
    std::cout << "углы " << A << ", " << B << ", " << C << ", " << D << ") ";
    if (a != c || b != d || A != C || B != D) throw MyException("стороны a,c и b,d попарно не равны или углы A,C и B,D попарно не равны");
    std::cout << "создан." << std::endl;
}
bool Parallelogram::check() {
    if (a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_) return true;
    else return false;
}
