#include <iostream>
#include <Windows.h>

#include "math.h"

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x1, x2;
    int operand;
    std::cout << "Введите первое число: ";
    std::cin >> x1;
    std::cout << "Введите второе число: ";
    std::cin >> x2;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operand;
    switch (operand)
    {
    case 1: std::cout << x1 << " плюс " << x2 << " = " << add(x1,x2);
        break;
    case 2: std::cout << x1 << " минус " << x2 << " = " << sub(x1, x2);
        break;
    case 3: std::cout << x1 << " умножить " << x2 << " = " << mult(x1, x2);
        break;
    case 4: std::cout << x1 << " разделить " << x2 << " = " << div(x1, x2);
        break;
    case 5: std::cout << x1 << " в степени " << x2 << " = " << pow(x1, x2);
        break;
    default: std::cout << "Вы указали неправильное число";
        break;
    } 
    
}