#include "stdafx.h"
#include "Circle.h"
namespace shp
{
	Circle::Circle(const std::string & name, DWORD rgbCur, const Point & center, size_t radius)
		//size_t instead unsigned int (for values [0,+.....]
		:Shape(name, rgbCur), m_Center(center), m_Radius(radius)
	{

	}

	Circle::~Circle()
	{

	}

	void Circle::draw(HDC hdc) 
	{ 
		if (nullptr != getBrush())
		{
			SelectBrush(hdc, getBrush());
		}
		//cout << "draw from Circle" << endl;
		Ellipse(hdc, m_Center.m_x - m_Radius, m_Center.m_y - m_Radius, m_Center.m_x + m_Radius, m_Center.m_y + m_Radius);
	}
}