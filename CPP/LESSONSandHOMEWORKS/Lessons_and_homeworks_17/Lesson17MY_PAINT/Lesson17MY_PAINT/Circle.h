#pragma once
#include "Shape.h"

namespace shp
{
	class Circle : public Shape
	{
	public:
		Circle(const std::string & name, const Point& center, size_t radius);
		//size_t instead unsigned int (for values [0,+.....]
		~Circle();
		virtual void draw(HDC hdc) override; // cout << "draw from Circle" << endl; 
	private:
		Point m_Center;
		size_t m_Radius;
	};
}
