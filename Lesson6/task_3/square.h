#pragma once

#include "parallelogram.h"

//�������
class Square : public Parallelogram {
public:
    Square(int a);
    bool check() override;
};