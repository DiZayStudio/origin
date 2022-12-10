#include <iostream>
#include <Windows.h>
#include <string>

#include "figure.h"
#include "triangle.h"
#include "quadrangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "parallelogram.h"
#include "rectangl.h"
#include "square.h"
#include "rhomb.h"


void print_info(Figure* f) {
    std::string check;
    f->print_info();
    f->print_sides();
    f->print_angle();
    if (f->check())
        check = "Правильная";
    else
        check = "Неправильная";
    std::cout << check << std::endl;
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure f0;
    Triangle f1(50, 60, 70, 10, 20, 30);
    Right_triangle f2(50, 60, 10, 20, 30);
    Isosceles_triangle f3(50, 60, 10, 20);
    Equilateral_triangle f4(30);

    Quadrangle f5(50, 60, 70, 80, 10, 20, 30, 40);
    Rectangl f6(10, 20);
    Square f7(20);
    Parallelogram f8(30, 40, 20, 30);
    Rhomb f9(30, 40, 30);

    print_info(&f0);
    print_info(&f1);
    print_info(&f2);
    print_info(&f3);
    print_info(&f4);
    print_info(&f5);
    print_info(&f6);
    print_info(&f7);
    print_info(&f8);
    print_info(&f9);
}