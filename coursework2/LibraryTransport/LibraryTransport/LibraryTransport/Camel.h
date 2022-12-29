#pragma once
#include "Transport.h"
#include <string>

class Camel : public Transport {
private:
	std::string Name;
	int DrivingTime;

public:
	Camel();
	double CalcDrivingTime(int way) override;
};