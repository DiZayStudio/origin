#include <iostream>
#include <Windows.h>
#include <string>
#include "LibraryTransport/race.h"
#include "LibraryTransport/Transport.h"
#include "LibraryTransport/Boots.h"
#include "LibraryTransport/Broom.h"
#include "LibraryTransport/Camel.h"
#include "LibraryTransport/Centaur.h"
#include "LibraryTransport/Eagle.h"
#include "LibraryTransport/FastCamel.h"
#include "LibraryTransport/FlyingCarpet.h"



void registration(Transport* tr[], Race* r) {
	int temp;

do {
		int j = 0;
		std::cout << r->info();
		std::cout << std::endl;
		
		if (r->getNumberTr() != 0) {
			std::cout << "Зарегистрированные транспортные средства: ";
		}
		for (int i = 0; i < 7; i++) {
			if(tr[i]->getCheck())
				std::cout << tr[i]->getName() << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < 7; i++) {
			std::cout << i+1 << ". " << tr[i]->getName() << std::endl;	
		}
		std::cout << "0. Закончить регистрацию\n";
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		std::cin >> temp;
		std::system("cls");
		if (temp != 0 && temp <= 7)
		{
			if (tr[temp - 1]->getType() == r->getMode() || r->getMode() == 2) {
				r->setNumberTr(r->getNumberTr() + 1);
				if (tr[temp - 1]->getCheck() == false) {
					tr[temp - 1]->setCheck(true);
					std::cout << tr[temp - 1]->getName() << " успешно зарегистрирован!\n";
				}
				else std::cout << tr[temp - 1]->getName() << " уже зарегистрирован!\n";
			}
			else std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
		} 

	} while (temp != 0);
}

void CalcDriving(Transport* tr[], Race r) {
	Transport* temp;

	for (int i = 0; i < 7; i++) {
		//if (tr[i]->getCheck() == true)
			tr[i]->setTime(tr[i]->CalcDrivingTime(r.getDist()));
	}
	
	for (int j = 1; j < 7; j++)
		for (int i = 0; i < 7 - 1; i++) {
		if (tr[i]->getTime() > tr[i + 1]->getTime()) {
			temp = tr[i];
			tr[i] = tr[i + 1];
			tr[i + 1] = temp;
		}
	}
	int j = 0;
	for (int i = 0; i < 7 ; i++) {
		if (tr[i]->getCheck() == true)
			std::cout << ++j << ". " << tr[i]->getName() << ". Время: " << tr[i]->getTime() << std::endl;
	}
};
void reset(Transport* tr[], Race* r) {
	for (int i = 0; i < 7; i++) {
		tr[i]->setCheck(false);
	}
	r->reset();
}

int main()
{
	int temp = 0;
	int typeGame = 0;
	int distance = 0;
	bool continueGame = true;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Race R;
	Transport* Tr[7];

	Boots t0;
	Broom t1;
	Camel t2;
	Centaur t3;
	Eagle t4;
	FastCamel t5;
	FlyingCarpet t6;
	
	Tr[0] = &t0;
	Tr[1] = &t1;
	Tr[2] = &t2;
	Tr[3] = &t3;
	Tr[4] = &t4;
	Tr[5] = &t5;
	Tr[6] = &t6;

	int mode = 0;

	std::cout << "Добро пожаловать в гоночный симулятор!\n";
	do {

		switch(mode) {
		case 0: {
			//Выбор типа гонки
			int n_mode = sizeof(modeName) / sizeof(modeName[0]);
			for (int i = 0; i < n_mode; i++) {
				std::cout << i+1 << ". " << modeName[i] << "\n";
			}
			std::cout << "Выберите тип гонки: ";
			std::cin >> typeGame;
			if(typeGame > 0 && typeGame <= n_mode)
				mode = 1;
			std::system("cls");
			break; }
		case 1: {
			//Выбор дистанции
			std::system("cls");
			std::cout << "Укажите длину дистанции (должна быть положительна): ";
			std::cin >> distance;

			R.setMode(typeGame-1);
			R.setDist(distance);

			mode = 2;
			break; }

		case 2: {
			//
			std::system("cls");
			std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства\n";
			std::cout << "1. Зарегистрировать транспорт\n";
			std::cout << "Выберите действие: ";

			std::cin >> temp;
			if (temp == 1) mode = 3;
			std::system("cls");
			break;
		}
		case 3: {
			//регистрация транспорта
			registration(Tr, &R);
			mode = 4;
			break; 
		}
		case 4: {
			std::cout << "1. Зарегистрировать транспорт\n";
			std::cout << "2. Начать гонку\n";
			std::cout << "Выберите действие: ";

			std::cin >> temp;
			if (temp == 1) mode = 3;
			if (temp == 2 && R.getNumberTr() > 1) {
				mode = 5;
			}
			else mode = 2;
			break;
		}
		case 5: {
			std::system("cls");
			std::cout << "Результаты гонки:\n";
			CalcDriving(Tr, R);


			std::cout << "\n1. Провести ещё одну гонку\n";
			std::cout << "2. Выйти\n";
			std::cout << "Выберите действие: ";
			std::cin >> temp;
			if (temp == 1) { 
				mode = 0;
				reset(Tr, &R);
			}
			if (temp == 2) mode = 10;
			break;
		}
		default:
			continueGame = false;
			break; 
		}
    
	} while (continueGame);
}

