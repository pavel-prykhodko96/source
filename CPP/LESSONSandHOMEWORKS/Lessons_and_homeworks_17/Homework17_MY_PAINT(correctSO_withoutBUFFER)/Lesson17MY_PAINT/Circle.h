#pragma once
#include "Shape.h"
#include "stdafx.h"

namespace shp
{
	class Circle : public Shape
	{
	public:
		Circle(const std::string & name, const Point& center, size_t radius);
		//size_t instead unsigned int (for values [0,+.....]
		~Circle();
		virtual void draw(HDC hdc) override; // cout << "draw from Circle" << endl; 
		Point getCNTR() { return m_Center; }
		size_t getRAD() { return m_Radius; }
		Point setCNTR (Point P) {  m_Center = P; }
		size_t setRAD (size_t R) { m_Radius = R; }
	private:
		Point m_Center;
		size_t m_Radius;
	};
}
