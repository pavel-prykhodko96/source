#pragma once
#include "Shape.h"

namespace shp
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(const std::string & name, const Point& leftTop,
			const Point& rightBottom);
		~Rectangle();
		virtual void draw(HDC hdc) override; // cout << "draw from Rectangle" << endl;
	private:
		Point m_leftTop;
		Point m_rightBottom;
	};
}