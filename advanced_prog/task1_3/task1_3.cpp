#include <functional>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <math.h>

const double PI = 3.1415926535;
double grad_to_rad(int x) { return x * PI / 180; }

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double angles[]{ 30, 60, 90 };


    std::cout << "[Входные данные]: ";
    for (const int& angle : angles) {
        std::cout << angle << " град (" << grad_to_rad(angle) << " рад) ";
    }

    std::vector<std::function<void(double)>> functions;

    functions.emplace_back([](double angle) {
        std::cout << "sin: " << std::sin(grad_to_rad(angle)) << " ";
        });

    functions.emplace_back([](double angle) {
        std::cout << "cos: " << std::cos(grad_to_rad(angle)) << " ";
        });

    std::cout << std::endl;
    std::cout << "[Выходные данные]: " << std::endl;

    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}