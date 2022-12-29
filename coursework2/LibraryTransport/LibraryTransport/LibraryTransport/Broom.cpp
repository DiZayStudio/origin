#include "Broom.h"

Broom::Broom() {
	Name = "Метла";
	Type = 2;
	Speed = 10;
}
double Broom::CalcDrivingTime(int way) {
	if (way < 1000) return way / Speed;
	else if (way < 5000) return (way * 0.97) / Speed;
	else if (way < 10000) return (way * 0.9) / Speed;
	else if (way >= 10000) return (way * 0.95) / Speed;
};