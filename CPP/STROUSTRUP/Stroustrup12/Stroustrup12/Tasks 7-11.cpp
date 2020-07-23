
#include "pch.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
using namespace Graph_lib;


int main()
{
	/*
	11. Нарисуйте ряд правильных многоугольников, вложенных
	друг в друга. Наиболее глубоко вложенный многоугольник
	должен быть равносторонним треугольником, вложенным в квадрат.
	вложенный в пятиугольник, и т.д.
	Для любителей математики: пусть все точки каждого N-угольника
	касаются сторон (N+l)-угольника. Указание: тригонометрические
	функции объявлены в заголовочном файле <cmath>
	(разделы 24.8, Б.9.2)
	*/

	Simple_window sWind(Point{ 0,0 }, 1280, 720, "My window #11");
	// x y
	Point pStartPoint(500, 400);
	//vector <vector<Point>*> vPoints;
	const double nLenght = 250; //pixels
	const double PI = 3.14;
	const int nDegreesInCircle = 360;
	// cos    sin
	Closed_polyline cpTriangle;
	cpTriangle.add(pStartPoint);
	Point cpTriangleSecPoint(nLenght * 0.5 + pStartPoint.x, nLenght* 0.86 + pStartPoint.y);
	cpTriangle.add(cpTriangleSecPoint);
	Point cpTriangleThrPoint(nLenght * 0.5 + cpTriangleSecPoint.x, - nLenght * 0.86 + cpTriangleSecPoint.y);
	cpTriangle.add(cpTriangleThrPoint);

	Closed_polyline cpSquare;
	cpSquare.add(pStartPoint);
	Point cpSquareSecPoint(nLenght * 0.258 + pStartPoint.x, nLenght * 0.965 + pStartPoint.y);
	cpSquare.add(cpSquareSecPoint);
	Point cpSquareThrPoint(nLenght * 0.965 + cpSquareSecPoint.x,- nLenght * 0.258 + cpSquareSecPoint.y);
	cpSquare.add(cpSquareThrPoint);
	Point cpSquareFrthPoint(-nLenght * 0.258 + cpSquareThrPoint.x,- nLenght * 0.965 + cpSquareThrPoint.y);
	cpSquare.add(cpSquareFrthPoint);

	Closed_polyline cpPent;
	cpPent.add(pStartPoint);
	Point cpPentSecPoint(nLenght * 0.309 + pStartPoint.x, nLenght * 0.951 + pStartPoint.y);
	cpPent.add(cpPentSecPoint);
	Point cpPentThrPoint(nLenght * 0.951 + cpPentSecPoint.x, -nLenght * 0.309 + cpPentSecPoint.y);
	cpPent.add(cpPentThrPoint);
	Point cpPentFrthPoint(nLenght * 0.309 + cpPentThrPoint.x, -nLenght * 0.951 + cpPentThrPoint.y);
	cpPent.add(cpPentFrthPoint);
	Point cpPentFifPoint(-nLenght * 0.951 + cpPentFrthPoint.x, -nLenght * 0.309 + cpPentFrthPoint.y);
	cpPent.add(cpPentFifPoint);

	

	/*Closed_polyline cpPent;
	cpPent.add(pStartPoint);
	Point cpPentSecPoint(nLenght * 0.104 + pStartPoint.x, nLenght * 0.994 + pStartPoint.y);
	cpPent.add(cpPentSecPoint);
	Point cpPentThrPoint(nLenght * 0.994 + cpPentSecPoint.x, - nLenght * 0.104 + cpPentSecPoint.y);
	cpPent.add(cpPentThrPoint);
	Point cpPentFrthPoint(  nLenght * 0.104 + cpPentThrPoint.x, - nLenght * 0.994 + cpPentThrPoint.y);
	cpPent.add(cpPentFrthPoint);
	Point cpPentFifPoint( - nLenght * 0.994 + cpPentFrthPoint.x, - nLenght * 0.104 + cpPentFrthPoint.y);
	cpPent.add(cpPentFifPoint);*/

	sWind.attach(cpTriangle);
	sWind.attach(cpSquare);
	sWind.attach(cpPent);
	sWind.wait_for_button();

}
	////10.
	//Simple_window sWind(Point{ 0,0 }, 1280, 600, "My window 10");
	//// x, y
	//Graph_lib::Rectangle chapter12_cpp{ Point{150,450},Point{250,500} };
	//Graph_lib::Rectangle Graph_cpp{ Point{50,350},Point{150,400} };	
	//Graph_lib::Rectangle Simple_window_h{ Point{300,350},Point{400,400} };	
	//Graph_lib::Rectangle GUI_cpp{ Point{550,350},Point{650,400} };	
	//Graph_lib::Rectangle window_cpp{ Point{250,250},Point{350,300} };	
	//Graph_lib::Rectangle GUI_h{ Point{550,250},Point{650,300} };	
	//Graph_lib::Rectangle Graph_h{ Point{50,150},Point{150,200} };	
	//Graph_lib::Rectangle Window_h{ Point{350,150},Point{450,200} };	
	//Graph_lib::Rectangle Point_h{ Point{100,50},Point{200,100} };	
	//Graph_lib::Rectangle FLTK_HEADERS{ Point{350,50},Point{450,100} };	
	//Graph_lib::Rectangle FLTK_CODE{ Point{600,50},Point{700,100} }; 
	//
	//chapter12_cpp.set_color(Color::dark_red);
	//Graph_cpp.set_color(Color::dark_red);
	//Simple_window_h.set_color(Color::dark_red);
	//GUI_cpp.set_color(Color::dark_red);
	//window_cpp.set_color(Color::dark_red);
	//GUI_h.set_color(Color::dark_red);
	//Graph_h.set_color(Color::dark_red);
	//Window_h.set_color(Color::dark_red);
	//Point_h.set_color(Color::dark_red);
	//FLTK_HEADERS.set_color(Color::dark_red);
	//FLTK_CODE.set_color(Color::dark_red);
	//
	//sWind.attach(chapter12_cpp);
	//sWind.attach(Graph_cpp);
	//sWind.attach(Simple_window_h);
	//sWind.attach(GUI_cpp);
	//sWind.attach(window_cpp);
	//sWind.attach(GUI_h);
	//sWind.attach(Graph_h);
	//sWind.attach(Window_h);
	//sWind.attach(Point_h);
	//sWind.attach(FLTK_HEADERS);
	//sWind.attach(FLTK_CODE);
	//
	//Line ch12_Graph(Point{ 200,450 }, Point{ 100,200 });
	//Line ch12_Sim_win(Point{ 200,450 }, Point{ 350,400 });
	//Line Graph_Graph(Point{ 100,350 }, Point{ 100,200 });
	//Line Sim_win_win(Point{ 350,350 }, Point{ 400,200 });
	//Line Sim_win_GUI(Point{ 350,350 }, Point{ 600,300 });
	//Line GUI_GUI(Point{ 600,350 }, Point{ 600,300 });
	//Line win_win(Point{ 300,250 }, Point{ 400,200 });
	//Line GUI_win(Point{ 600,250 }, Point{ 400,200 });
	//Line GUI_FLTK(Point{ 600,250 }, Point{ 400,100 });
	//Line Graph_point(Point{ 100,150 }, Point{ 150,100 });
	//Line Graph_FLTK(Point{ 100,150 }, Point{ 400,100 });
	//Line win_point(Point{ 400,150 }, Point{ 150,100 });
	//Line win_FLTK(Point{ 400,150 }, Point{ 400,100 });
	//Line FLTKCODE_FLTK(Point{ 600,75 }, Point{ 450,75 });
	//ch12_Graph.set_color(Color::black);
	//ch12_Sim_win.set_color(Color::black);
	//Graph_Graph.set_color(Color::black);
	//Sim_win_win.set_color(Color::black);
	//Sim_win_GUI.set_color(Color::black);
	//GUI_GUI.set_color(Color::black);
	//win_win.set_color(Color::black);
	//GUI_win.set_color(Color::black);
	//GUI_FLTK.set_color(Color::black);
	//Graph_point.set_color(Color::black);
	//Graph_FLTK.set_color(Color::black);
	//win_point.set_color(Color::black);
	//win_FLTK.set_color(Color::black);
	//FLTKCODE_FLTK.set_color(Color::black);
	//sWind.attach(ch12_Graph);
	//sWind.attach(ch12_Sim_win);
	//sWind.attach(Graph_Graph);
	//sWind.attach(Sim_win_win);
	//sWind.attach(Sim_win_GUI);
	//sWind.attach(GUI_GUI);
	//sWind.attach(win_win);
	//sWind.attach(GUI_win);
	//sWind.attach(GUI_FLTK);
	//sWind.attach(Graph_point);
	//sWind.attach(Graph_FLTK);
	//sWind.attach(win_point);
	//sWind.attach(win_FLTK);
	//sWind.attach(FLTKCODE_FLTK);
	//sWind.wait_for_button();
	/*//9.
	Simple_window sWind(Point{ 0,0 },1280,600,"My window #9");
	Image iMyPhoto(Point{ 100,100 }, "20181019_110957194_iOS.jpg");
	Text tMyName(Point{ 50,50 }, "Pasha Prykhodko");
	sWind.attach(iMyPhoto);
	sWind.attach(tMyName);
	sWind.set_label("Pasha Prykhodko");
	sWind.wait_for_button();
	return 0;
	*/
	//8.
	//Simple_window sWind(Point{ 0,0 }, 1280, 600, "My window #8");
	//Circle cFir{ Point {100,100},50 };
	//Circle cSec{ Point {150,150},50 };
	//Circle cThird{ Point {200,100},50 };
	//Circle cFourth{ Point {250,150},50 };
	//Circle cFifth{ Point {300,100},50 };
	//cFir.set_color(Color::blue);
	//cSec.set_color(Color::yellow);
	//cThird.set_color(Color::black);
	//cFourth.set_color(Color::dark_green);
	//cFifth.set_color(Color::dark_red);
	//cFir.set_style(Line_style(Line_style::solid, 10));
	//cSec.set_style(Line_style(Line_style::solid, 10));
	//cThird.set_style(Line_style(Line_style::solid, 10));
	//cFourth.set_style(Line_style(Line_style::solid, 10));
	//cFifth.set_style(Line_style(Line_style::solid, 10));
	//sWind.attach(cFir);
	//sWind.attach(cSec);
	//sWind.attach(cThird);
	//sWind.attach(cFourth);
	//sWind.attach(cFifth);
	//sWind.wait_for_button();
	//return 0;
	//7. Нарисуйте двумерный дом анфас, как это делают дети : дверь,
	//два окна и крыша с дымовой трубой.Детали можете выбрать
	//сами, можете даже нарисовать дымок из трубы.
	//Получилось не в анфас а со стороной но без окон и двери
	//Simple_window sWind (Point{ 50,50 }, 1280, 640, "My window #7");
	//
	//Graph_lib::Polygon pFrontSide;
	//pFrontSide.add(Point{ 100, 500 });
	//pFrontSide.add(Point{ 300, 500 });
	//pFrontSide.add(Point{ 300, 350 });
	//pFrontSide.add(Point{ 100, 350 });
	//pFrontSide.set_color(Color::dark_green);
	//Graph_lib::Polygon pRightSide;
	//pRightSide.add(Point{ 300, 500 });
	//pRightSide.add(Point{ 550, 400 });
	//pRightSide.add(Point{ 550, 250 });
	//pRightSide.add(Point{ 300, 350 });
	//pRightSide.set_color(Color::dark_green);
	//Graph_lib::Polygon pFrontRoof;
	//pFrontRoof.add(Point{ 100, 350 });
	//pFrontRoof.add(Point{ 200, 250 });
	//pFrontRoof.add(Point{ 300, 350 });
	//pFrontRoof.set_color(Color::dark_red);
	//Graph_lib::Polygon pRightRoof;         
	//pRightRoof.add(Point{ 300, 350 });
	//pRightRoof.add(Point{ 550, 250 });
	//pRightRoof.add(Point{ 450, 150 });
	//pRightRoof.add(Point{ 200, 250 });
	//pRightRoof.set_color(Color::dark_red);
	//sWind.attach(pFrontSide);
	//sWind.attach(pRightSide);
	//sWind.attach(pFrontRoof);
	//sWind.attach(pRightRoof);
	//sWind.wait_for_button();
	//return 0;
