#include <iostream>
#include "square.h"

//�������
Square::Square(int a) : Parallelogram(90, 90, a, a) {
    this->name_ = "�������";
}
bool Square::check() {
    if (a_ == b_ && b_ == c_ && c_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
    else return false;
}


