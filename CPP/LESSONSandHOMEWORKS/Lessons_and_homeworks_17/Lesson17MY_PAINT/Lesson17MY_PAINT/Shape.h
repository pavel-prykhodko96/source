#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

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
		Shape(const std::string & name);
		~Shape();
		virtual void draw(HDC hdc); // cout << "draw from Shape" << endl;
	private:
		std::string m_name;
	};
}

