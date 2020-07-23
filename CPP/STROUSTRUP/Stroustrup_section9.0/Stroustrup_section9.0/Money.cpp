
#include "pch.h"
#include "../../std_lib_facilities.h"

enum class currency
{uah,rub,usd,dkk};

class Money
{
public:
	Money(double input, currency m);
	Money() { f_c = 0; d = 0; c = 0; m = currency::usd; }
	currency m;
	long int full_in_cents() { return f_c; };
	int dollar() { return d; }
	int cent() { return c; }
private:
	long int f_c;
	int d;
	int c;
};
Money::Money(double input, currency m) :m{m}
{
	input *= 1000;
	f_c = input;
	d = f_c / 1000;
	c = f_c % 1000 / 10;
	if (f_c % 10 >= 5)
		c += 1;
}
Money operator + (Money& a, Money& b)
{
	if (a.m == currency::usd)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 28, currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 49, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 15, currency::usd);
		};
	if (a.m == currency::uah)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 / 28, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 , currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 *2, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 /2, currency::usd);
		};
	if (a.m == currency::rub)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000*100, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 78, currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 5, currency::usd);
		};
	if (a.m == currency::dkk)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 15, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 25, currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 * 1000, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 +
				(double)b.full_in_cents() / 1000 , currency::usd);
		};
}
Money operator - (Money& a, Money& b)
{
	if (a.m == currency::usd)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 28, currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 49, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 15, currency::usd);
		};
	if (a.m == currency::uah)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 654, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 , currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 491, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 5, currency::usd);
		};
	if (a.m == currency::rub)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 53, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 2, currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 , currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 157, currency::usd);
		};
	if (a.m == currency::dkk)
		switch (b.m)
		{
		case currency::usd:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 13, currency::usd);
		case currency::uah:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 78, currency::usd);
		case currency::rub:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000 * 19, currency::usd);
		case currency::dkk:
			return Money((double)a.full_in_cents() / 1000 -
				(double)b.full_in_cents() / 1000, currency::usd);
		};
}
Money operator * (Money& a, Money& b)
{
	error("Wrong operator");
	return Money(0, currency::usd);
}
Money operator / (Money& a, Money& b)
{
	error("Wrong operator");
	return Money(0, currency::usd);
}
istream& operator >> (istream & is, Money& a)
{
	string cy = "";
	char c1, c2, c3;
	double val;
	currency m = currency::usd;
	is >> c1 >> c2 >> c3 >> val;
	if (!is) return is;
	cy += c1;
	cy += c2;
	cy += c3;
	if (cy == "usd") m = currency::usd;
	else if (cy == "rub") m = currency::rub;
	else if (cy == "uah") m = currency::uah;
	else if (cy == "dkk") m = currency::dkk;
	else
	{	                             //Format error
		is.clear(ios_base::failbit); //Place bit of error
		error("Wrong currency");
		return is;
	}
	Money input(val, m);
	a = input;
	return is;
}
ostream& operator << (ostream& os, Money& a)
{
	string cy;
	switch (a.m)
	{
	case currency::usd: cy = "usd";
		break;
	case currency::rub: cy = "rub";
		break;
	case currency::uah: cy = "uah";
		break;
	case currency::dkk: cy = "dkk";
		break;
	}
	return os << a.dollar() << "." << a.cent() << cy;
}
int main()
try {
	Money m1;
	Money m2;
	cin >> m1;
	cin >> m2;
	Money result = m1 + m2;
	cout << result << endl;
}
catch (runtime_error& e)
{
	cerr << e.what();
}