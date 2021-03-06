
/* 
1. Напишите программу, создающую пустое окно Simple_window 
размером 600х400 пикселей с меткой Му window, скомпилируйте ее, 
скомпонуйте и выполните. Помните о том, что вы должны подключить 
библиотеку FLTК, описанную в приложении Г, включить в свой код 
заголовочные файлы Graph.h и Simple_Window.h, а также включить 
в проект файлы Graph.срр и Window.срр.

2. Добавьте по одному примеры из раздела 12.7, выполняя 
тестирование после каждого добавленного подраздела. 

3. Выполните программу, внеся небольшие изменения
(например, измените цвет, местоположение фигур или 
количество точек) в каждом из примеров.
*/

#include "pch.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	Point t1(100, 100);
	Simple_window win(t1, 600, 400, "My window");
	win.wait_for_button();

	Axis xa(Axis::x, Point(20, 350), 300, 15, "x-ord");
	xa.set_color(Color::dark_cyan);
	xa.label.set_color(Color::dark_magenta);

	win.attach(xa);
	win.wait_for_button();

	Axis ya(Axis::y, Point(20, 350), 300, 15, "y-ord");
	ya.set_color(Color::dark_cyan);
	ya.label.set_color(Color::dark_magenta);

	win.attach(ya);
	win.wait_for_button();
	
	Function sine{ sin,0,100,Point(20,175),2000,45,60 };
	sine.set_color(Color::dark_cyan);
	
	win.attach(sine);
	win.wait_for_button();

	Graph_lib::Polygon poly;
	poly.add(Point{ 200,250 });
	poly.add(Point{ 300,100 });
	poly.add(Point{ 400,250 });
	poly.set_color(Color::dark_red);
	poly.set_style(Line_style::dashdotdot);

	win.attach(poly);
	win.wait_for_button();
	
}
catch (...)
{
	cerr << "Something went wrong!";
}

