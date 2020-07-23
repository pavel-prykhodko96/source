#pragma once
#include "Shape.h"
#include "stdafx.h"

namespace shp
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(const std::string & name, const Point& leftTop,
			const Point& rightBottom);
		~Rectangle();
		virtual void draw(HDC hdc) override; // cout << "draw from Rectangle" << endl;
		Point getLT() { return m_leftTop; }
		Point getRB() { return m_rightBottom; }
		Point setLT(Point LT) {  m_leftTop = LT; }
		Point setRB(Point RB) {  m_rightBottom = RB; }
	private:
		Point m_leftTop;
		Point m_rightBottom;
	};
}