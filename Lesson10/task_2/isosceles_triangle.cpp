#include <iostream>
#include "isosceles_triangle.h"

//равнобедренный треугольник
    Isosceles_triangle::Isosceles_triangle(int A, int B, int a, int b) : Triangle(A, B, A, a, b, a) {
        this->name_ = "Равнобедренный треугольник";
    }
    bool Isosceles_triangle::check() {
        if (a_ == c_ && A_ == C_) return true;
        else return false;
    }