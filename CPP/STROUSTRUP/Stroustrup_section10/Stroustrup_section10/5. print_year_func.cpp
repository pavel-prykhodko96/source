
#include "pch.h"

const int not_a_reading = -7777;
const int not_a_month = -1;

struct Day 
{
	vector<double> hour { vector<double>(24,not_a_reading) }; 
};
struct Month 
{
	int month{ not_a_month };
	vector<Day> day { 31 }; 
}; 
struct Year
{
	int year;
	vector <Month> month{ 12 };
};
struct Reading
{
	int day;
	int hour;
	double temperature;
};
void print_year(ofstream& ost, Year y)
{
	ost << "{ year: " << y.year << " }\n";
	for (int k=0;k<y.month.size();++k)
	{
		ost << "  { month: " << k+1 << " }\n";
		for (int i=0;i<y.month[k].day.size();++i)
		{
			ost << "    { day:" << i+1 << " }\n";
			for (int j = 0; j < y.month[k].day[i].hour.size(); ++j)
			{
				if (y.month[k].day[i].hour[j]!=not_a_reading)
				ost << "      { hour: " << j << " temp: "
					<< y.month[k].day[i].hour[j] << " }\n";
			}
		}
	}
}
int main()
{
	Year y;
	ofstream ost("ABCD.txt");
	print_year(ost, y);
	return 0;
}