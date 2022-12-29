#include "Boots.h"

Boots::Boots() {
	Name = "Ботинки-вездеходы";
	Type = 1;
	Speed = 6;
	DrivingTime = 60;
}
double Boots::CalcDrivingTime(int way) {
	int time = way / Speed;
	int nRest = time / DrivingTime;
	if (nRest == 0) return time;
	else if (nRest == 1) return time + 10;
	else return time + 10 + (nRest - 1) * 5;
}; 