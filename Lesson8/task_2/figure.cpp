#include "figure.h"
#include <iostream>

Figure::Figure() {
    sides_count_ = 0;
    name_ = "Фигура";
};
Figure::Figure(int sides_count) {
    sides_count_ = sides_count;
    name_ = "Фигура";
    std::cout << name_ << " (количество сторон = " << sides_count_ << ") ";
    if (sides_count != 0) throw MyException("Количество сторон не равно 0");
    std::cout << "создан.";
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
