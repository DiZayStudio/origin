#include <iostream>
#include <Windows.h>

struct bank_account {
	int number;
	std::string owner_name;
	double money;
};

void change_maney(bank_account& a, double maney) {
	a.money = maney;
}

int main()
{	
//	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	bank_account account;
	double money;

	std::cout << "Введите номер счёта: ";
	std::cin >> account.number;

	std::cout << "Введите имя владельца: ";
	std::cin >> account.owner_name;

	std::cout << "Введите баланс: ";
	std::cin >> account.money;

	std::cout << "Введите новый баланс: ";
	std::cin >> money;

	change_maney(account, money);

	std::cout << "Ваш счёт: " << account.owner_name << ", " << account.number << ", " << account.money << std::endl;

}

