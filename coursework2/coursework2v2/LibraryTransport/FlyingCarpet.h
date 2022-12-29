#pragma once
#include "Transport.h"
#include <string>

class FlyingCarpet : public Transport {
private:
	std::string Name;

public:
	FlyingCarpet();
	double CalcDrivingTime(int way) override;
	std::string getName() override;
	void setCheck(bool ch) override;
	bool getCheck() override;
};