#include <iostream>
#include "parallelogram.h"

//��������������

Parallelogram::Parallelogram(int A, int B, int a, int b) :Quadrangle(A, B, A, B, a, b, a, b) {
    this->name_ = "��������������";
}
bool Parallelogram::check() {
    if (a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_) return true;
    else return false;
}
