#include "pch.h"
#include "Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y) 
{
	cout << "Point was created for "
		<< this << endl;
};
void Point::show() { cout << "(" << m_x << "," << m_y << ")\n"; }
Point::~Point() { cout << "Point was destroyed for " << this << endl; }