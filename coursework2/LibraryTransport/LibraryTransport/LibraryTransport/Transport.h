#pragma once

class Transport {
protected:
	int Speed;
	int Type;
public:
	Transport();
	virtual double CalcDrivingTime(int way);
};