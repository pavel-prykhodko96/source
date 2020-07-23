#include "stdafx.h"
#include "Rectangle.h"

namespace shp
{
	Rectangle::Rectangle(const std::string & name, DWORD rgbCur, const Point& leftTop,
		const Point& rightBottom)
		: Shape(name,rgbCur), m_leftTop(leftTop), m_rightBottom(rightBottom)
	{

	}
	Rectangle::~Rectangle() = default;

	void Rectangle::draw(HDC hdc) 
	{ 
		if (nullptr != getBrush())
		{
			SelectBrush(hdc, getBrush());
		}
		//cout << "draw from Rectangle" << endl; 
		::Rectangle(hdc, m_leftTop.m_x, m_leftTop.m_y, m_rightBottom.m_x, m_rightBottom.m_y);
	}
}