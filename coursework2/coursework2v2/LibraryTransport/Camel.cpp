#include "Camel.h"

	Camel::Camel() {
		Name = "Верблюд";
		Type = 0;
		Speed = 10;
		DrivingTime = 30;
		Check = false;
	}
	double Camel::CalcDrivingTime(int way) {
		int time = way / Speed;
		int nRest = time / DrivingTime;
		if (nRest == 0) return time;
		else if (nRest == 1) return time + 5;
		else return time + 5 + (nRest - 2) * 8;
	};

	std::string Camel::getName() {
		return this->Name;
	}

	void Camel::setCheck(bool ch) {
		Check = ch;
	}

	bool Camel::getCheck() {
		return Check;
	}
