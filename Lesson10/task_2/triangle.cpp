#include <iostream>
#include "triangle.h"

Triangle::Triangle(int A, int B, int C, int a, int b, int c) {
        sides_count_ = 3;
        name_ = "Треугольник";
        this->A_ = A;
        this->B_ = B;
        this->C_ = C;
        this->a_ = a;
        this->b_ = b;
        this->c_ = c;
}
void Triangle::print_sides() {
    std::cout << "Стороны:";
    std::cout << " a=" << this->a_ << " b=" << this->b_ << " c=" << this->c_ << std::endl;
}

void Triangle::print_angle() {
    std::cout << "Углы:";
    std::cout << " A=" << this->A_ << " B=" << this->B_ << " C=" << this->C_ << std::endl;
}
void Triangle::print_info() {
    Figure::print_info();
}
bool Triangle::check() {
    if (sides_count_ == 3 && (A_ + B_ + C_ == 180)) return true;
    else return false;
}
