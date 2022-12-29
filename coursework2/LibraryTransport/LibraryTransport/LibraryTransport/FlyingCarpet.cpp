#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet() {
	Name = "Ботинки-вездеходы";
	Type = 2;
	Speed = 10;
}
double FlyingCarpet::CalcDrivingTime(int way) {
	int coef = way / 1000;
	return (way * (100 - coef) / 100.0) / Speed;
};