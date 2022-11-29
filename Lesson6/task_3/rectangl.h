#pragma once

#include "parallelogram.h"

//прямоугольник
class Rectangl : public Parallelogram {
public:
    Rectangl(int a, int b);
    bool check() override;
};
