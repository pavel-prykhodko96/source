
#include "pch.h"
#include "Line.h"
#include "Point.h"

Line::Line(int a_x, int a_y, int b_x, int b_y)
	: a(a_x, a_y), b(b_x, b_y)
{
	distance = sqrt(pow(b_x - a_x, 2) + pow(b_y - a_y, 2));
}
Line::~Line() {}
Point Line::get_a() { return a; }
Point Line::get_b() { return b; }
double Line::get_dist() { return distance; }