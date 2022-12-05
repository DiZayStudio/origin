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
#include "MyException.h"
#include <stdexcept>


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

    try {
        Figure f0(1);
 //       Triangle f1(60, 70, 60, 10, 20, 30);
 //       Right_triangle f2(60, 60, 60, 3, 4, 5);
 //       Isosceles_triangle f3(60, 60, 60, 20, 10, 20);
 //       Equilateral_triangle f4(60, 60, 60, 20, 20, 20);

 //       Quadrangle f5(50, 70, 70, 80, 10, 20, 30, 40);
 //       Rectangl f6(90, 90, 90, 90, 1, 2, 1, 2);
 //       Square f7(90, 90, 90, 90, 2, 2, 2, 2);
 //       Parallelogram f8(100, 80, 100, 80, 2, 3, 2, 2);
 //       Rhomb f9(100, 80, 100, 80, 2, 3, 2, 2);

    }
    catch (MyException err){
        std::cout << "Причина: " << err.what() << std::endl;
    }


}