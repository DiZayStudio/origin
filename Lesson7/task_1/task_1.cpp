#include <iostream>
#include <Windows.h>

#define MODE  1

#if MODE==1
int add(int x1, int x2) {
	return x1 + x2;
}
#endif

#ifndef MODE
#error It is necessary to define MODE
#endif

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#if MODE==0
	std::cout << "Работаю в режиме тренировки\n";
#elif MODE==1
	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Введите число 1: ";
	int x1, x2;
	std::cin >> x1;
	std::cout << "Введите число 2: ";
	std::cin >> x2;
	std::cout << "Результат сложения: " << add(x1,x2);
#else
	std::cout << "Неизвестный режим. Завершение рабооты!\n";
#endif
   
}

