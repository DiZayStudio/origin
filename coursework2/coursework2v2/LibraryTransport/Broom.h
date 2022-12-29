#pragma once
#include "Transport.h"
#include <string>

class Broom : public Transport {
private:
	std::string Name;

public:
	Broom();
	double CalcDrivingTime(int way) override;
	std::string getName() override;
	void setCheck(bool ch) override;
	bool getCheck() override;
};