
#include "pch.h"
#include <iostream>
using namespace std;

class Point
{
	int m_x;
	int m_y;
public:
	Point(int x, int y) : m_x(x), m_y(y) { cout << "Point was created for " << this << endl; };
	void show() { cout << "(" << m_x << "," << m_y << ")\n"; }
	~Point() { cout << "Point was destroyed for " << this << endl; }
};

class Circle
{
private:
	Point m_pPoint;
	int m_R;
public:
	Circle(int x, int y, int R) :m_pPoint(x,y), m_R(R)
	{
		if (m_R < 0) m_R = 0;
		cout << "Circle was created for " << this << endl;
	}
	Circle(Point P, int R) :m_pPoint(P), m_R(R)
	{
		if (m_R < 0) m_R = 0;
		cout << "Circle was created for " << this << endl;
	}
	~Circle()
	{
		cout << "Circle was destroyed for " << this << endl;
	}
};

int main()
{
	Point p(5, 6);
	Circle first(p, -13);
}