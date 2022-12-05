#pragma once

#include "parallelogram.h"
#include "MyException.h"

//прямоугольник
class Rectangl : public Parallelogram {
public:
    Rectangl(int A, int B, int C, int D, int a, int b, int c, int d);
    bool check() override;
};
