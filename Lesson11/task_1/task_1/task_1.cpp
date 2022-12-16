#include <iostream>
#include <string>
#include <Windows.h>

#include "greeter.h"
#include "Leaver.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Greet::Greeter g;
	Dynamic::Leaver l;

	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << g.greet(name);
	std::cout << std::endl;
	std::cout << l.leave(name);
}
