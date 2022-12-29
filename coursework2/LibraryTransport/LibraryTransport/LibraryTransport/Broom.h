#pragma once
#include "Transport.h"
#include <string>

class Broom : public Transport {
private:
	std::string Name;

public:
	Broom();
	double CalcDrivingTime(int way) override;
};