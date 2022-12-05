#pragma once

#include "parallelogram.h"
#include "MyException.h"

//квадрат
class Square : public Parallelogram {
public:
    Square(int A, int B, int C, int D, int a, int b, int c, int d);
    bool check() override;
};