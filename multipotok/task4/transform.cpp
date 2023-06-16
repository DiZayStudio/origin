#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)
{
	TypeShape type = shape.getType();

	if (type < circle)
	{
		shape.p1.x += m; shape.p1.y += n;
		shape.p2.x += m; shape.p2.y += n;
	}
	if (type >= line && type < circle) {
		shape.p3.x += m; shape.p3.y += n;
		shape.p4.x += m; shape.p4.y += n;
	}
	if (type == cube) {
		shape.p1.z += k;
		shape.p2.z += k;
		shape.p3.z += k;
		shape.p4.z += k;
		shape.p5.x += m; shape.p5.y += n; shape.p5.z += k;
		shape.p6.x += m; shape.p6.y += n; shape.p6.z += k;
	}
	return shape;
}


Shape transform::scaleX(int a)
{
	TypeShape type = shape.getType();
	if (type < circle)
	{
		shape.p1.x *= a;
		shape.p2.x *= a;
	}
	if (type >= line && type < circle) {
		shape.p3.x *= a;
		shape.p4.x *= a;
	}
	if (type == cube) {
		shape.p5.x *= a; 
		shape.p6.x *= a; 
	}
	return shape;
}

Shape transform::scaleY(int d)
{
	TypeShape type = shape.getType();
	if (type < circle)
	{
		shape.p1.y *= d;
		shape.p2.y *= d;
	}
	if (type >= line && type < circle) {
		shape.p3.y *= d;
		shape.p4.y *= d;
	}
	if (type == cube) {
		shape.p5.y *= d;
		shape.p6.y *= d;
	}
	return shape;
}

Shape transform::scaleZ(int e)
{
	TypeShape type = shape.getType();
	if (type < circle)
	{
		shape.p1.z *= e;
		shape.p2.z *= e;
	}
	if (type >= line && type < circle) {
		shape.p3.z *= e;
		shape.p4.z *= e;
	}
	if (type == cube) {
		shape.p5.z *= e;
		shape.p6.z *= e;
	}
	return shape;
}

Shape transform::scale(int s)
{
	TypeShape type = shape.getType();
	
	if (type < circle)
	{
		shape.p1.x /= s; shape.p1.y /= s;
		shape.p2.x /= s; shape.p2.y /= s;
	}
	if (type >= line && type < circle) {
		shape.p3.x /= s; shape.p3.y /= s;
		shape.p4.x /= s; shape.p4.y /= s;
	}
	if (type == cube) {
		shape.p1.z /= s;
		shape.p2.z /= s;
		shape.p3.z /= s;
		shape.p4.z /= s;
		shape.p5.x /= s; shape.p5.y /= s; shape.p5.z /= s;
		shape.p6.x /= s; shape.p6.y /= s; shape.p6.z /= s;
	}
	return shape;
}