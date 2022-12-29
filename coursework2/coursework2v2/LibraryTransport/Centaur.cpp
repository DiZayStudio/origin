#include "Centaur.h"

Centaur::Centaur() {
	Name = "Кентавр";
	Type = 0;
	Speed = 15;
	DrivingTime = 8;
	Check = false;
}
double Centaur::CalcDrivingTime(int way) {
	int time = way / Speed;
	int nRest = time / DrivingTime;
	if (nRest == 0) return time;
	else return time + nRest * 2;
};

std::string Centaur::getName() {
	return this->Name;
}

void Centaur::setCheck(bool ch) {
	Check = ch;
}

bool Centaur::getCheck() {
	return Check;
}