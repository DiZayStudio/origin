#pragma once

enum TypeShape { line, sqr, cube, circle, cylinder };

 struct Point {
	int x = 0;
	int y = 0;
	int z = 0;
};

class Shape {
public:
	TypeShape type;
	Point p1, p2, p3, p4, p5, p6, p7, p8;
	double volume;
	double square;
	double height;
	double radius;
public:
	Shape() = default;
	Shape(TypeShape type);

	TypeShape getType();
	double Get_volume();
	double Get_square();
	double Get_height();
	double Get_radius();
};


class Line : public Shape {
public:
	Line();
	Line(TypeShape type, Point p1, Point p2);
};

class Square : public Shape {
public:
	Square(Point p1, Point p2, Point p3, Point p4);
};

class Cube : public Shape {
public:
	Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8);
};

class Circle : public Shape {
private:
	Point center;
public:
	Circle(Point center, double r);
};

class Cylinder : public Shape {
private:
	Point center;
public:
	Cylinder(Point center, double r, double h);
};
