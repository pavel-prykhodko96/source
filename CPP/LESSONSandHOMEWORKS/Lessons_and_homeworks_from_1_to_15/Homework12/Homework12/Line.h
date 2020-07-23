#pragma once

class Point;
class Line
{
	Point a;
	Point b;
	double distance;
public:
	Line(int a_x, int a_y, int b_x, int b_y);
	~Line();
	Point get_a();
	Point get_b();
	double get_dist();
};

