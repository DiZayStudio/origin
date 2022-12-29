#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet() {
	Name = "Ковёр-самолёт";
	Type = 1;
	Speed = 10;
	Check = false;
}
double FlyingCarpet::CalcDrivingTime(int way) {
	if (way < 1000) return way / Speed;
	else if (way < 5000) return (way * 0.97) / Speed;
	else if (way < 10000) return (way * 0.9) / Speed;
	else if (way >= 10000) return (way * 0.95) / Speed;
	return 0;
};

std::string FlyingCarpet::getName() {
	return this->Name;
}

void FlyingCarpet::setCheck(bool ch) {
	Check = ch;
}

bool FlyingCarpet::getCheck() {
	return Check;
}