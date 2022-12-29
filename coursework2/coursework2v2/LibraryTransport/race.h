#pragma once
#include <string>

std::string modeName[3]{
	"Гонка для наземного транспорта.",
	"Гонка для воздушного транспорта.",
	"Гонка для наземного и воздушного транспорта."
};

class Race {
protected:
	int mode;
	int dist;
	int numberTr;

public:
	Race();
	Race(int mode, int dist);

	std::string info();
	void reset();
	void setMode(int mode);
	void setDist(int dist);
	void setNumberTr(int n);
	int getNumberTr();
	int getMode();
	int getDist();
};