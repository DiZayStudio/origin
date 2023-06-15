#pragma once

const enum class type_shape { line, sqr, cube, circle, cilinder };

 struct Point {
	int x = 0;
	int y = 0;
	int z = 0;
};


class Shape {
protected:
	int type;
	double volume;
	double square;
	double height;
	double radius;
public:
	Shape() = default;
	Shape(int type);

	int getType();
	int Get_volume();
	int Get_square();
	int Get_height();
	int Get_radius();

	void shift(int m, int n, int k) override;
	void scaleX(int a);
	void scaleY(int d);
	void scaleZ(int e);
	void scale(int s);
};


class Line : public Shape {
protected:
	Point p1;
	Point p2;
public:
	Line();
	Line(Point p1, Point p2);
};


class Square : public Shape {
private:
	// вершины
	Point p1, p2, p3, p4;
public:
	Square(Point p1, Point p2, Point p3, Point p4);
};

class Cube : public Shape {
private:
	Point p1, p2, p3, p4, p5, p6, p7, p8;
	// стороны фигуры
public:
	Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8);
};

class Circle : public Shape {
private:
	Point center;
	// стороны фигуры
public:
	Circle(Point center, double r);
};

class Cylinder : public Shape {
private:
	Point center;
	// стороны фигуры
public:
	Cylinder(Point center, double r, double h);
};
