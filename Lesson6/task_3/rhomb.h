#pragma once

#include "parallelogram.h"

//����
class Rhomb : public Parallelogram {
public:
    Rhomb(int A, int B, int a);
    bool check() override;
};
