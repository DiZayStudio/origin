#include "Eagle.h"

Eagle::Eagle() {
	Name = "Îð¸ë";
	Type = 1;
	Speed = 8;
	Check = false;
}
double Eagle::CalcDrivingTime(int way) {
	return (way * 0.94) / Speed;
};

std::string Eagle::getName() {
	return this->Name;
}

void Eagle::setCheck(bool ch) {
	Check = ch;
}

bool Eagle::getCheck() {
	return Check;
}