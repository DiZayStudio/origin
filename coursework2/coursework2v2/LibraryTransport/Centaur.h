#pragma once
#include "Transport.h"
#include <string>

class Centaur : public Transport {
private:
	std::string Name;
	int DrivingTime;

public:
	Centaur();
	double CalcDrivingTime(int way) override;
	std::string getName() override;
	void setCheck(bool ch) override;
	bool getCheck() override;
};
