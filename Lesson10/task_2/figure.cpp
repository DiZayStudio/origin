#include "figure.h"
#include <iostream>

Figure::Figure() {
    sides_count_ = 0;
    name_ = "Фигура";
};

void Figure::print_sides() {}
void Figure::print_angle() {}
void Figure::print_info() {
    std::cout << name_ << std::endl;
    std::cout << "Количество сторон: " << sides_count_ << std::endl;
}
bool Figure::check() {
    if (sides_count_ == 0) return true;
    else return false;
}
