#include <iostream>
#include "rhomb.h"

//ромб
Rhomb::Rhomb(int A, int B, int a) :Parallelogram(A, B, a, a) {
    this->name_ = "Ромб";
}
bool Rhomb::check() {
    if (a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_) return true;
    else return false;
}