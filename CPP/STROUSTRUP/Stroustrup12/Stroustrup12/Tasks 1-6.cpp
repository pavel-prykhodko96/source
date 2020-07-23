


#include "pch.h"
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	
//
//	//1.
//	Simple_window win(Point{ 50,50 }, 1024, 768, "MY_WINDOW");
//	
//	Graph_lib::Rectangle rRectangle(Point{50,50}, 250, 100);
//	rRectangle.set_color(Color::dark_blue);
//	win.attach(rRectangle);
//
//	Graph_lib::Polygon pRectangle;
//
//	pRectangle.add(Point{ 250,150 });
//	pRectangle.add(Point{ 250,250 });
//	pRectangle.add(Point{ 650,250 });
//	pRectangle.add(Point{ 650,150 });
//	pRectangle.set_color(Color::dark_red);
//	win.attach(pRectangle);
//
//	win.wait_for_button();
//
//	//2.
//	Simple_window win(Point{ 50,50 }, 1024, 768, "MY_WINDOW");
//
//	Point pFr(200, 100);
//	Graph_lib::Rectangle rFrame(pFr, 100, 30);
//	rFrame.set_color(Color::dark_green);
//	win.attach(rFrame);
//
//	Text tFrame(Point(200,130), "Howdy!");
//	tFrame.set_font_size(30);
//	win.attach(tFrame);
//
//	win.wait_for_button();
//
////3
//	Simple_window win(Point{ 50,50 }, 800, 600, "My window");
//
//	Graph_lib::Open_polyline pLetterP;
//	pLetterP.add(Point{ 100,250 });
//	pLetterP.add(Point{ 100,100 });
//	pLetterP.add(Point{ 175,100 });
//	pLetterP.add(Point{ 175,175 });
//	pLetterP.add(Point{ 100,175 });
//	pLetterP.set_style(Line_style(Line_style::solid, 6));
//	pLetterP.set_color(Color::blue);
//
//	Graph_lib::Open_polyline pLetterS;
//	pLetterS.add(Point{ 200,250 });
//	pLetterS.add(Point{ 275,250 });
//	pLetterS.add(Point{ 275,175 });
//	pLetterS.add(Point{ 200,175 });
//	pLetterS.add(Point{ 200,100 });
//	pLetterS.add(Point{ 275,100 });
//	pLetterS.set_style(Line_style(Line_style::solid, 6));
//	pLetterS.set_color(Color::dark_blue);
//
//	win.attach(pLetterP);
//	win.attach(pLetterS);
//
//	win.wait_for_button();
//
////4.
//Simple_window sWind(Point{ 50,50 }, 800, 600, "My window #4");
//const int SIDESIZE = 5;
//vector <Graph_lib::Rectangle*> vRects;
//for (int i = 1; i < SIDESIZE+1;++i)
//	for (int j = 1; j < SIDESIZE+1; ++j)
//	{
//		Graph_lib::Rectangle* rRect = new Graph_lib::Rectangle(Point { 100 * j,100 * i }, Point { 100 + 100 * j,100 + 100 * i });
//		if ((i + j) % 2 == 0) rRect->set_fill_color(Color::black);
//		else rRect->set_fill_color(Color::white);
//		vRects.push_back(rRect);
//	}
//for (auto & r : vRects)
//	sWind.attach(*r);
//sWind.wait_for_button();
//for (auto & r : vRects)
//	delete r;
	//
	////5.
	//Simple_window sWind{ Point {0,0},1600,900,"My window #5" };
	//Graph_lib::Rectangle rRect(Point{ 100,100 }, Point{ 1166,775 });
	//rRect.set_color(Color::dark_red);
	//rRect.set_style(Line_style(Line_style::solid, 25));
	//sWind.attach(rRect);
	//sWind.wait_for_button();
	//Simple_window sWind{ Point {0,0},1600,900,"My window #6" };
	//Graph_lib::Rectangle rRect{ Point{0,0},Point {1700,1000} };
	//rRect.set_fill_color(Color::dark_green);
	//sWind.attach(rRect);
	//sWind.wait_for_button();
	/*

}