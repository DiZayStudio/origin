#include <iostream>
#include "rectangl.h"

//прямоугольник
Rectangl::Rectangl(int a, int b) :Parallelogram(90, 90, a, b) {
    this->name_ = "Прямоугольник";
}
bool Rectangl::check() {
    if (a_ == c_ && b_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
    else return false;
}
