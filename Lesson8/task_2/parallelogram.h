#pragma once

#include "quadrangle.h"
#include "MyException.h"

//��������������
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int A, int B, int C, int D, int a, int b, int c, int d);
    bool check() override;
};