#pragma once

#include "parallelogram.h"

//�������������
class Rectangl : public Parallelogram {
public:
    Rectangl(int a, int b);
    bool check() override;
};
