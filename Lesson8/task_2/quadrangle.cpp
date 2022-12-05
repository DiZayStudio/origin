#include <iostream>
#include "quadrangle.h"


Quadrangle::Quadrangle(int A, int B, int C, int D, int a, int b, int c, int d) {
    
    sides_count_ = 4;
    name_ = "Четырёхугольник";
    this->A_ = A;
    this->B_ = B;
    this->C_ = C;
    this->D_ = D;
    this->a_ = a;
    this->b_ = b;
    this->c_ = a;
    this->d_ = b;
    std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; ";
    std::cout << "углы " << A << ", " << B << ", " << C << ", " << D << ") ";
    if (A + B + C + D != 360) throw MyException("сумма углов не равна 360");
    std::cout << "создан." << std::endl;
}
void Quadrangle::print_sides() {
    std::cout << "Стороны:";
    std::cout << " a=" << this->a_ << " b=" << this->b_ << " c=" << this->c_ << " d=" << this->d_ << std::endl;
}
void Quadrangle::print_angle() {
    std::cout << "Углы:";
    std::cout << " A=" << this->A_ << " B=" << this->B_ << " C=" << this->C_ << " D=" << this->D_ << std::endl;
}
void Quadrangle::print_info() {
    Figure::print_info();
}
bool Quadrangle::check() {
    if (sides_count_ == 4 && (A_ + B_ + C_ + D_ == 360)) return true;
    else return false;
}
