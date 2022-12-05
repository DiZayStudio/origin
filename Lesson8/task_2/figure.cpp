#include "figure.h"
#include <iostream>

Figure::Figure() {
    sides_count_ = 0;
    name_ = "������";
};
Figure::Figure(int sides_count) {
    sides_count_ = sides_count;
    name_ = "������";
    std::cout << name_ << " (���������� ������ = " << sides_count_ << ") ";
    if (sides_count != 0) throw MyException("���������� ������ �� ����� 0");
    std::cout << "������.";
};

void Figure::print_sides() {}
void Figure::print_angle() {}
void Figure::print_info() {
    std::cout << name_ << std::endl;
    std::cout << "���������� ������: " << sides_count_ << std::endl;
}
bool Figure::check() {
    if (sides_count_ == 0) return true;
    else return false;
}
