#include <iostream>
#include <Windows.h>


void registration() {
	int temp;
	do {
		std::cout << "1. Зарегистрировать транспорт\n";
		std::cout << "Выберите действие: ";

		std::cin >> temp;


	} while (false);
}

int main()
{
	int typeGame = 0;
	int distance = 0;
	bool continueGame = false;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::cout << "Добро пожаловать в гоночный симулятор!\n";

	do {
		std::cout << "1. Гонка для наземного транспорта\n";
		std::cout << "2. Гонка для воздушного транспорта\n";
		std::cout << "3. Гонка для наземного и воздушного транспорта\n";
		std::cout << "Выберите тип гонки: ";
		std::cin  >> typeGame;

		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		std::cin >> distance;

		std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства\n";

		registration();


	} while (continueGame);
}

