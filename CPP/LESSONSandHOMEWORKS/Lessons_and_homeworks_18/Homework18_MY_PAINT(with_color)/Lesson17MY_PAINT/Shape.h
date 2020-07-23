#pragma once
#include "stdafx.h"

namespace shp
{
	struct Point //initialize by {7,8} - OK m_x = 7, m_y = 8;
				 //for classes' private members it doesn't work
	{
		int m_x;
		int m_y;
	};

	class Shape
	{
	public:
		Shape(const std::string & name, DWORD rgbCur);
		~Shape();
		virtual void draw(HDC hdc);
		std::string getName() { return m_name; }
		HBRUSH getBrush() { return m_hBrush; }
		DWORD getRgb() { return m_rgbCur; }
	private:
		HBRUSH m_hBrush;
		DWORD m_rgbCur;
		std::string m_name;
	};
}

