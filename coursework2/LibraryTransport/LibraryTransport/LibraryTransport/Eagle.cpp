#include "Eagle.h"

Eagle::Eagle() {
	Name = "Îð¸ë";
	Type = 2;
	Speed = 8;
}
double Eagle::CalcDrivingTime(int way) {
	return (way * 0.94) / Speed;
};