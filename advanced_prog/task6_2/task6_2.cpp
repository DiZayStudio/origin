#include <iostream>
#include <set>
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size=0;
    std::set<int> n;
    int num;

    std::cout << "Введите число вводимых символов: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> num;
        n.insert(num);
    }

    std::cout << "[OUT]:" << std::endl;

    for (auto i = n.end(); i != n.begin();) {
        i--;
        std::cout << *i << std::endl;
    }
}
