#include "Boots.h"

Boots::Boots() {
	Name = "Ботинки-вездеходы";
	Type = 0;
	Speed = 6;
	DrivingTime = 60;
	Check = false;
}
double Boots::CalcDrivingTime(int way) {
	int time = way / Speed;
	int nRest = time / DrivingTime;
	if (nRest == 0) return time;
	else if (nRest == 1) return time + 10;
	else return time + 10 + (nRest - 1) * 5;
};

std::string Boots::getName() {
	return this->Name;
}

void Boots::setCheck(bool ch) {
	Check = ch;
}

bool Boots::getCheck() {
	return Check;
}
