#include <iostream>

enum months {
	january = 1,
	february,
	march,
	april,
	may,
	june,
	july,
	august, 
	september,
	october,
	november,
	december
};

void print_month(int number_month) {
	switch (number_month) {
	case months::january:
		std::cout << "Январь" << std::endl;
		break;
	case months::february:
		std::cout << "Февраль" << std::endl;
		break;
	case months::march:
		std::cout << "Март" << std::endl;
		break;
	case months::april:
		std::cout << "Апрель" << std::endl;
		break;
	case months::may:
		std::cout << "Май" << std::endl;
		break;
	case months::june:
		std::cout << "Июнь" << std::endl;
		break;
	case months::july:
		std::cout << "Июль" << std::endl;
		break;
	case months::august:
		std::cout << "Август" << std::endl;
		break;
	case months::september:
		std::cout << "Сентябрь" << std::endl;
		break;
	case months::october:
		std::cout << "Октябрь" << std::endl;
		break;
	case months::november:
		std::cout << "Ноябрь" << std::endl;
		break;
	case months::december:
		std::cout << "Декабрь" << std::endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int number_month = 0;
	do {
		
		std::cout << "Введите номер месяца: ";
		std::cin >> number_month;

		if (number_month > 12 || number_month < 0) {
			std::cout << "Неправильный номер!" << std::endl;
			continue;
		}
		else {
			print_month(number_month);
		}

	} while (number_month != 0);	
}

