#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Point
{
	
public:
	Point(int x, int y);
	void show();
	~Point();
	int m_x;
	int m_y;
};
