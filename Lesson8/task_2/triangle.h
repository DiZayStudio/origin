#pragma once

#include "figure.h"
#include "MyException.h"

class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;

public:
    Triangle(int A, int B, int C, int a, int b, int c);
    void print_sides() override;

    void print_angle() override;
    void print_info() override;
    bool check() override;
};