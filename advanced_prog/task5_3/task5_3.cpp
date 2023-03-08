#include <iostream>
#include "Windows.h"

class Functor {
private:
    int sum = 0;
    int count = 0;

public:
    void operator()(int val) {
        if (val % 3 == 0) {
            sum += val;
            count++;
        }
    }

    void printCount() { std::cout << "get_count() = " << count << std::endl; }

    void printSum() { std::cout << "get_sum() = " << sum << std::endl; }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 4, 1, 3, 6, 25, 54 };

    std::cout << " Исходный массив:" << std::endl;

    Functor fun;

    for (auto num : arr) {
        std::cout << " " << num;
        fun(num);
    }
    std::cout << std::endl;

    fun.printSum();
    fun.printCount();
}
