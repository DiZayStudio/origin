#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

// длина отрезка
int Length(Point a, Point b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Shape::Shape(TypeShape type) {
	this->type = type;
	p1, p2, p3, p4, p5, p6, p7, p8;
}

TypeShape Shape::getType() {
	return type; 
}

double Shape::Get_volume(){
	 return this->volume;
}
double Shape::Get_square() {
	return this->square;
}
double Shape::Get_height() {
	return this->height;
}
double Shape::Get_radius() {
	return this->radius;
}

Line::Line() {
	this->type = line;
	this->p1.x = 0; this->p1.y = 0; this->p1.z = 0;
	this->p2.x = 0; this->p2.y = 0; this->p2.z = 0;
}

Line::Line(TypeShape type, Point p1, Point p2) {
	this->type = type;
	this->p1 = p1;
	this->p2 = p2;
}


Square::Square(Point p1, Point p2, Point p3, Point p4) {
	this->type = sqr;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	// стороны фигуры
	int a = Length(p1, p2);
	int b = Length(p2, p3);

	this->square = a * b;
}

Cube::Cube(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8) {
	this->type = cube;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->p5 = p5;
	this->p6 = p6;
	this->p7 = p7;
	this->p8 = p8;
	// стороны фигуры
	int a = Length(p1, p2);
	int b = Length(p2, p3);
	int c = Length(p4, p5);

	this->square = 2 * a * b + 2 * a * c + 2 * b * c;
	this->volume = a * b * c;
}

Circle::Circle(Point center, double r) {
	this->type = circle;
	this->center = center;
	this->radius = r;
	this->square = M_PI * radius * radius;
}

Cylinder::Cylinder(Point center, double r, double h) {
	this->type = cylinder;
	this->center = center;
	this->radius = r;
	this->height = h;
	this->square = M_PI * radius * radius + 2 * radius * height;
	this->volume = M_PI * radius * radius * height;
}