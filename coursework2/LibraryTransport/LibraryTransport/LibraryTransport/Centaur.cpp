#include "Centaur.h"

Centaur::Centaur() {
	Name = "Кентавр";
	Type = 1;
	Speed = 15;
	DrivingTime = 8;
}
double Centaur::CalcDrivingTime(int way) {
	int time = way / Speed;
	int nRest = time / DrivingTime;
	if (nRest == 0) return time;
	else return time + nRest * 2;
};