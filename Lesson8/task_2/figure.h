#pragma once
#include <string>
#include "MyException.h"

class Figure {
protected:
    std::string name_;
    int sides_count_;

public:
    Figure();
    Figure(int sides_count);

    virtual void print_sides();
    virtual void print_angle();
    virtual void print_info();
    virtual bool check();
};