
#include "pch.h"
#include "task_change_chrono.h"

namespace Chrono
{//definition of function-members
	Date::Date(long int s)
	{
		if (s < 1) throw Invalid();
		score_ = s;
		long_to_date(s);
		if (!is_date(y, m, d)) throw Invalid();
	}

	void Date::add_day(int n)
	{
		n += d;
		int days_in_month = 31;
		switch (m)
		{
		case Month::feb: days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun:
		case Month::sep: case Month::nov:
			days_in_month = 30;
			break;
		}
		while (n > days_in_month)
		{
			n -= days_in_month;
			add_month(1);
		}
		d = n;
	}
	Month operator++(Month& m)
	{
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
		return m;
	}
	void Date::add_month(int n)
	{
		n += (int)m;
		while (n > 12)
		{
			n -= 12;
			add_year(1);
		}
		switch (n)
		{
		case 1: m = Month::jan;
			break;
		case 2: m = Month::feb;
			break;
		case 3: m = Month::mar;
			break;
		case 4: m = Month::apr;
			break;
		case 5: m = Month::may;
			break;
		case 6: m = Month::jun;
			break;
		case 7: m = Month::jul;
			break;
		case 8: m = Month::aug;
			break;
		case 9: m = Month::sep;
			break;
		case 10: m = Month::oct;
			break;
		case 11: m = Month::nov;
			break;
		case 12: m = Month::dec;
			break;
		}
	}
	void Date::add_year(int n)
	{
		if (m == Month::feb&&d == 29 && leapyear(y + n))
		{
			m = Month::mar;
			d = 1;
		}
		y += n;
	}
	void Date::long_to_date(long int s)
	{
		int days_in_month = 31;
		for (long int i = 1; i <= s; ++i)
		{
			add_day(1);
		}
	}
	bool is_date(int y, Month m, int d)
	{
		if (d <= 0)return false;
		if (m < Month::jan || Month::dec < m)return false;
		int days_in_month = 31;
		switch (m)
		{
		case Month::feb: days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun:
		case Month::sep: case Month::nov:
			days_in_month = 30;
			break;
		}
		if (days_in_month < d) return false;
		return true;
	}
	bool leapyear(int y)
	{
		if (y % 4 == 0) return true;
		else return false;
	}
	bool operator ==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator !=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << int(d.month())
			<< ',' << d.day() << ')';
	}
	/*istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch3 != ')')
		{                                //Format error
			is.clear(ios_base::failbit); //Place bit of error
			return is;
		}
		dd = Date(y, Month(m), d);
		return is;
	}*/
};
