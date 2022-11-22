#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
protected:
	std::string name;
	int sides_count;

public:
	Figure() {
		sides_count = 0;
		name = "Фигура";
	};
	int get_sides_count() {
		return sides_count;
	}
	std::string get_name() {
		return name;
	}
};

class Triangle : public Figure {
public:
	Triangle() {
		sides_count = 3;
		name = "Треугольник";
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle() {
		sides_count = 4;
		name = "Четырёхугольник";
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure f1;
	Triangle f2;
	Quadrangle f3;
	std::cout << "Количество сторон:\n";
	std::cout << f1.get_name() << ": " << f1.get_sides_count() << std::endl;
	std::cout << f2.get_name() << ": " << f2.get_sides_count() << std::endl;
	std::cout << f3.get_name() << ": " << f3.get_sides_count() << std::endl;
}