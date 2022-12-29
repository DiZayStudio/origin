#pragma once
#include "Transport.h"
#include <string>

class FlyingCarpet : public Transport {
private:
	std::string Name;

public:
	FlyingCarpet();
	double CalcDrivingTime(int way) override;
};