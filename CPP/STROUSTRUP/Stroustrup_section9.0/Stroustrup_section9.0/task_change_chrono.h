
#include "pch.h"
#include "../../std_lib_facilities.h"

namespace Chrono
{
	enum class Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date
	{
	public:
		class Invalid {};//For generating exceptions
		Date(long int s);//Checking is it correct and initialize 
		//non-modifying operations:
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		//modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		
	private:
		int y = 1970;
		Month m = Month::jan;
		int d = 1;
		void long_to_date(long int s);
		long int score_;
	};
	
	bool is_date(int y, Month m, int d);//true for correct date
	bool leapyear(int y);               //true for leap (высокосный) year
	bool operator == (const Date& a, const Date& b);
	bool operator != (const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	//istream& operator>>(istream& is, Date& dd);
}//Chrono


