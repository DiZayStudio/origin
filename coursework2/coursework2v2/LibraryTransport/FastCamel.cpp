#include "FastCamel.h"

FastCamel::FastCamel() {
	Name = "Верблюд-быстроход";
	Type = 0;
	Speed = 40;
	DrivingTime = 10;
	Check = false;
}

double FastCamel::CalcDrivingTime(int way) {
	int time = way / Speed;
	int nRest = time / DrivingTime;
	if (nRest == 0) return time;
	else if (nRest == 1) return time + 5;
	else if (nRest == 2) return time + 5 + 6.5;
	else return time + 5 + 6.5 + (nRest - 2) * 8;
};

std::string FastCamel::getName() {
	return this->Name;
}

void FastCamel::setCheck(bool ch) {
	Check = ch;
}

bool FastCamel::getCheck() {
	return Check;
}