#include "Transport.h"

Transport::Transport() {
	Speed = 0;
	Type = 0;
	Check = 0;
	Time = 0;
};

double Transport::CalcDrivingTime(int way) {	
	return 0;
};

std::string Transport::getName() {
	return "";
};

void Transport::setCheck(bool ch) {
	Check = ch;
}

bool Transport::getCheck() {
	return Check;
}

int Transport::getType() {
	return Type;
}

void Transport::resetTime() {
	Time = 0;
}

void Transport::setTime(double time) {
	Time = time;
}

double Transport::getTime() {
	return Time;
}
