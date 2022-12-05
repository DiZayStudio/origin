#pragma once

#include "figure.h"
#include "MyException.h"

class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;

public:
    Quadrangle(int A, int B, int C, int D, int a, int b, int c, int d);
    void print_sides() override;
    void print_angle() override;
    void print_info() override;
    bool check() override;
};
