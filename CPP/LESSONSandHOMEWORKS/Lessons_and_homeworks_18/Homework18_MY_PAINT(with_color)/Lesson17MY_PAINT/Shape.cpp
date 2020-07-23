#include "stdafx.h"
#include "Shape.h"

namespace shp
{
	Shape::Shape(const std::string & name, DWORD rgbCur) : m_name{ name }, m_rgbCur(rgbCur)
	{
		if (m_rgbCur!=0)
			m_hBrush = CreateSolidBrush(m_rgbCur);
	}
	Shape::~Shape()
	{

	}
	void Shape::draw(HDC hdc) { std::cout << "draw from Shape" << std::endl; }
}
