#include <iostream>
#include "right_triangle.h"

//прямоугольный треугольник
Right_triangle::Right_triangle(int A, int B, int a, int b, int c) : Triangle(A, B, 90, a, b, c) {
    this->name_ = "Прямоугольный треугольник";
}
bool Right_triangle::check() {
    if (C_ == 90) return true;
    else return false;
}