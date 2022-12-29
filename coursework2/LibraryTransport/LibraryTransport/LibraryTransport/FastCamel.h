#pragma once
#include "Transport.h"
#include <string>

class FastCamel : public Transport {
private:
	std::string Name;
	int DrivingTime;

public:
	FastCamel();
	double CalcDrivingTime(int way) override;
};