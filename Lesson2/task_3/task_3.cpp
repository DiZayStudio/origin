#include <iostream>
#include <Windows.h>

struct address {
	std::string city;
	std::string street;
	int houm;
	int flat;
	int postcode;
};

void print_address(address& a) {
	std::cout << "Город: " << a.city << std::endl;
	std::cout << "Улица: " << a.street << std::endl;
	std::cout << "Номер дома: " << a.houm << std::endl;
	std::cout << "Номер квартиры: " << a.flat << std::endl;
	std::cout << "Индекс: " << a.postcode << std::endl;
	std::cout << std::endl;
}

void add_address(address& a) {
	std::cout << "Введите город: ";
	std::cin >> a.city;

	std::cout << "Введите  улицу: ";
	std::cin >> a.street;

	std::cout << "Введите номер дома: ";
	std::cin >> a.houm;

	std::cout << "Введите номер квартиры: ";
	std::cin >> a.flat;

	std::cout << "Введите индекс: ";
	std::cin >> a.postcode;
	std::cout << std::endl;
}

int main()
{
	//	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	address a, b;

	a.city = "Москва";
	a.street = "Арбат";
	a.houm = 12;
	a.flat = 8;
	a.postcode = 123456;

	b.city = "Ижевск";
	b.street = "Пушкина";
	b.houm = 59;
	b.flat = 143;
	b.postcode = 953769;

//	address c;
//	add_address(c);

	print_address(a);
	print_address(b);

//	print_address(c);
}