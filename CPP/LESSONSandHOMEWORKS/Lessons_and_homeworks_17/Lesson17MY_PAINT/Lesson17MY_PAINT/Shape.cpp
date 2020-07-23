#include "stdafx.h"
#include "Shape.h"

namespace shp
{
	Shape::Shape(const std::string & name) : m_name{ name }
	{

	}
	Shape::~Shape()
	{

	}
	void Shape::draw(HDC hdc) { cout << "draw from Shape" << endl; }
}
