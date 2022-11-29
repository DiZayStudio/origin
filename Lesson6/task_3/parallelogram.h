#pragma once

#include "quadrangle.h"

//ןאנאככוכמדנאלל
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int A, int B, int a, int b);
    bool check() override;
};