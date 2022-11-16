#include <iostream>
#include <Windows.h>

class Calculator {
private:
     double num1, num2;

public:
    Calculator() {
        this->num1 = 0;
        this->num2 = 0;
    }
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else return false;
    }
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else return false;
    }
    double add() {
        return num1 + num2;
    }
    double subtract_1_2() {
        return num1 - num2;
    }
    double subtract_2_1() {
        return num2 - num1;
    }
    double multiply() {
        return num1 * num2;
    }
    double divide_1_2() {
        return num1 / num2;
    }
    double divide_2_1() {
        return num2 / num1;
    }
};

void input(Calculator& c) {
    double n1, n2;
    bool temp1 = true, temp2 = true;
    do {
        std::cout << "Введите num1: ";
        std::cin >> n1; 
        if (c.set_num1(n1))
            temp1 = false;
        else
        std::cout << "Неверный ввод!" << std::endl;
    } while (temp1);

    do {
        std::cout << "Введите num2: ";
        std::cin >> n2;
        if (c.set_num2(n2))
            temp2 = false;
        else
            std::cout << "Неверный ввод!" << std::endl;
    } while (temp2);
}
void print(Calculator& c) {
    std::cout << "num1 + num2 = " << c.add() << std::endl;
    std::cout << "num1 - num2 = " << c.subtract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << c.subtract_2_1() << std::endl;
    std::cout << "num1 * num2 = " << c.multiply() << std::endl;
    std::cout << "num1 / num2 = " << c.divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << c.divide_2_1() << std::endl;
    // Для удобства восприятия сделаем отступ
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Calculator calculator;

    while (true) {
        input(calculator);

        print(calculator);
    }
}

