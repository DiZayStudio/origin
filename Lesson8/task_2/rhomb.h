#pragma once

#include "parallelogram.h"
#include "MyException.h"

//ромб
class Rhomb : public Parallelogram {
public:
    Rhomb(int A, int B, int C, int D, int a, int b, int c, int d);
    bool check() override;
};
