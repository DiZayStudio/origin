#include "race.h"

Race::Race() {
	this->mode = 0;
	this->dist = 0;
	numberTr = 0;
};
Race::Race(int mode, int dist) {
	this->mode = mode;
	this->dist = dist;
	numberTr = 0;
};

std::string Race::info() {
	std::string temp = modeName[this->mode] + " Расстояние: " + std::to_string(this->dist);
	return temp;
};
void Race::reset() {
	mode = 0;
	dist = 0;
	numberTr = 0;
};
void Race::setMode(int mode) {
	this->mode = mode;
};

void Race::setDist(int dist) {
	this->dist = dist;
};

void Race::setNumberTr(int n) {
	this->numberTr = n;
};

int Race::getNumberTr() {
	return numberTr;
};

int Race::getMode() {
	return mode;
}

int Race::getDist() {
	return dist;
}

