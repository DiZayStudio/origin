#include <iostream>
#include "right_triangle.h"

//прямоугольный треугольник
Right_triangle::Right_triangle(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
    this->name_ = "Прямоугольный треугольник ";

    
    std::cout << name_ << " (стороны " << a << ", " << b << ", " << c << "; ";
    std::cout << "углы " << A << ", " << B << ", " << C << ") ";
    if (C != 90) throw MyException("Угол С не равен 90");
    std::cout << "создан." << std::endl; 
}
bool Right_triangle::check() {
    if (C_ == 90) return true;
    else return false;
}