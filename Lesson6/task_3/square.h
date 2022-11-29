#pragma once

#include "parallelogram.h"

//квадрат
class Square : public Parallelogram {
public:
    Square(int a);
    bool check() override;
};