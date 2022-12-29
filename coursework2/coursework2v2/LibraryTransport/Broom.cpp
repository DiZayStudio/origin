#include "Broom.h"

Broom::Broom() {
	Name = "Метла";
	Type = 1;
	Speed = 20;
	Check = false;
}
double Broom::CalcDrivingTime(int way) {
	int coef = way / 1000;
	return (way * (100 - coef) / 100.0) / Speed;
};

std::string Broom::getName() {
	return this->Name;
}


void Broom::setCheck(bool ch) {
	Check = ch;
}

bool Broom::getCheck() {
	return Check;
}