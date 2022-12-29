#pragma once

#include "Transport.h"
#include <string>

class Eagle : public Transport {
private:
	std::string Name;
	
public:
	Eagle();
	double CalcDrivingTime(int way) override;
	std::string getName() override;
	void setCheck(bool ch) override;
	bool getCheck() override;
};