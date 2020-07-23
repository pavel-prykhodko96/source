#include "stdafx.h"
#include "Rectangle.h"

namespace shp
{
	Rectangle::Rectangle(const std::string & name, const Point& leftTop,
		const Point& rightBottom)
		: Shape(name), m_leftTop(leftTop), m_rightBottom(rightBottom)
	{

	}
	Rectangle::~Rectangle() 
	{

	}

	void Rectangle::draw(HDC hdc) 
	{ 
		//cout << "draw from Rectangle" << endl; 
		::Rectangle(hdc, m_leftTop.m_x, m_leftTop.m_y, m_rightBottom.m_x, m_rightBottom.m_y);
	}
}