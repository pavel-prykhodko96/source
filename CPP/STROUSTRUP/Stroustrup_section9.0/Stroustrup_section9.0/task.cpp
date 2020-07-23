

#include "pch.h"
#include "../../std_lib_facilities.h"

//enum Month 
//{jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};

class Date
{
public:
	Date(int y, int m, int d);
	Date():y{ 1000 }, m{ 1 }, d{ 1 }{} //Start day, Sunday
	void add_day(int n);
	int month() const  { return m; }
	int day() const{ return d; }
	int year() const { return y; }
private:
	int y;
	int m;
	int d;
};
Date::Date(int y, int m, int d) : y{ y }, m{ m }, d{ d }
{
	if (m >= 1 && m <= 12 && d>= 1 && d <= 31)
	{
		return;
	}
	else error("Wrong date!");
};
void Date::add_day(int n)
{
	d += n;
	if (d > 31)
	{
		while (d > 31)
		{
			d -= 31;
			++m;
			if (m > 12)
			{
				m = 1;
				++y;
			}
		}
	}
}
Date next_workday(const Date& today) //???
{
	Date start; 
	if (today.year() < start.year()) error("Uncurrent year!");
	for (int i = 1; ;++i)
	{
		start.add_day(1);
		if (((start.day() > today.day() && start.month() >= today.month() && start.year() >= today.year())
		||(start.month() > today.month() && start.year() >= today.year())
		|| (start.year() > today.year())) && (i % 7 >= 1 && i % 7 <= 5))
		{
			return start;
		}
	}
}
int week_of_the_year(const Date& today)
{
	Date start;
	int counter_of_weeks(0);
	for (int i = 1; ; ++i)
	{
		if (start.day() == today.day() && start.month() == today.month())
			return counter_of_weeks;
		if (i % 7 == 1)
			++counter_of_weeks;
		start.add_day(1);
	}

}
ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}
int main()
try{
	Date today(2005, 12, 31);
	cout << today << endl;
	cout << week_of_the_year(today) << endl;
}
catch (runtime_error&e)
{
	cerr << e.what();
}