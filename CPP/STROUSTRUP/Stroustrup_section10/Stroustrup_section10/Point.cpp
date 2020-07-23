
#include "pch.h"

struct Point
{
	int x;
	int y;
};

int main()
{
	cout << "Please enter the 7 pairs of coordinate 'x' and 'y':\n";
	vector <Point> original_points;
	Point p_buff;
	for ( int i = 0; i < 7; ++i)
	{
		
		cin >> p_buff.x >> p_buff.y;
		original_points.push_back(p_buff);
	}
	string name = "mydata.txt";
	ofstream ost(name);
	if (!ost) error("Impossible to open output file: ", name);
	for (Point point : original_points)
	{
		ost << point.x << " " << point.y << endl;
	}
	ost.close();
	vector <Point> processed_points;
	ifstream ist(name);
	for (;ist >> p_buff.x >> p_buff.y; )
		processed_points.push_back(p_buff);
	ist.close();
	for (Point point : original_points)
	{
		cout << point.x << " " << point.y << endl;
	}
	for (Point point : processed_points)
	{
		cout << point.x << " " << point.y << endl;
	}
	if (original_points.size() != processed_points.size())
		error("Smth is wrong!");
	for (int i = 0; i < original_points.size(); ++i)
	{
		if (original_points[i].x!=processed_points[i].x
			|| original_points[i].y != processed_points[i].y)
			error("Smth is wrong!");
	}
}