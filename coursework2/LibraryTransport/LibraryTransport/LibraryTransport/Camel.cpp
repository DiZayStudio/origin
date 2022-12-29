#include "Camel.h"

	Camel::Camel() {
		Name = "Верблюд";
		Type = 1;
		Speed = 10;
		DrivingTime = 30;
	}
	double Camel::CalcDrivingTime(int way) {
		int time = way / Speed;
		int nRest = time / DrivingTime;
		if (nRest == 0) return time;
		else if (nRest == 1) return time + 5;
		else return time + 5 + (nRest - 1) * 8;
	};
