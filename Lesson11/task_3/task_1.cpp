#include <iostream>
#include <string>
#include <Windows.h>

#include "Leaver.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dynamic::Leaver l;

	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;

	std::cout << l.leave(name);
}
