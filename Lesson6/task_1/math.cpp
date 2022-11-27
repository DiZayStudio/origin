#include "math.h"

double add(double x1, double x2) {
	return x1 + x2;
}
double sub(double x1, double x2) {
	return x1 - x2;
}
double mult(double x1, double x2) {
	return x1 * x2;
}
double div(double x1, double x2) {
	return x1 / x2;
}
double pow(double x1, double x2) {
	for (int i=1; i < static_cast<int> (x2); i++) {
		x1 *= x1;
	}
	return x1;
}