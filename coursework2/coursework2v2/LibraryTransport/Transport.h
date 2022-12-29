#pragma once
#include <string>

class Transport {
protected:
	int Speed;
	int Type;
	bool Check;
	double Time;

public:
	Transport();
	virtual double CalcDrivingTime(int way);
	virtual std::string getName();
	virtual void setCheck(bool ch);
	virtual bool getCheck();
	int getType();
	void resetTime();
	void setTime(double time);
	double getTime();
};