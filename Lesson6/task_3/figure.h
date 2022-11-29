#pragma once
#include <string>

class Figure {
protected:
    std::string name_;
    int sides_count_;

public:
    Figure();

    virtual void print_sides();
    virtual void print_angle();
    virtual void print_info();
    virtual bool check();
};