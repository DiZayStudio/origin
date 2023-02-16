#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

std::vector<int> arr{ 4, 7, 9, 14, 12 };

void print() {

}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Входные данные: ";
    std::for_each(arr.begin(), arr.end(), [](int num) { std::cout << num << ' '; });
    std::cout << '\n';

    std::cout << "Выходные данные: ";

    std::for_each(arr.begin(), arr.end(), [](int num) mutable
        {
            if (num % 2 != 0) num *= 3;
    std::cout << num << ' ';
        });
}