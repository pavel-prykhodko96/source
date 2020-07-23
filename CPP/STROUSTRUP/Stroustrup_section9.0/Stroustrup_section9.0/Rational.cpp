
#include "pch.h"
#include "../../std_lib_facilities.h"

class Rational
{
public:
	Rational (int num, int den) : n{ num }, d{ den } {}
	Rational() { n = 1; d = 1; }
	double rat_to_double() { return (double)n / (double)d; }
	void operator = (int num)
	{
		n = num;
		d = 1;
		return;
	}
	int n; //numerator
	int d; //denominator
private:
	
};
Rational operator + (Rational& left, Rational& right)
{
	Rational result(0,0);
	for (int i = 1;; ++i)
	{
		for (int j = 1; left.d*i >= right.d*j; ++j)
		{
			if (left.d*i == right.d*j)
			{
				left.n = left.n*i;
				right.n = right.n*j;
				result.d = left.d*i;
				result.n = right.n + left.n;
				return result;
			}
		}
	}
}
Rational operator - (Rational&left, Rational&right)
{
	Rational result(0, 0);
	for (int i = 1;; ++i)
	{
		for (int j = 1; left.d*i >= right.d*j; ++j)
		{
			if (left.d*i == right.d*j)
			{
				left.n = left.n*i;
				right.n = right.n*j;
				result.d = left.d*i;
				result.n = left.n - right.n;
				return result;
			}
		}
	}
}
Rational operator *(Rational&left, Rational&right)
{
	Rational result(0, 0);
	result.n = left.n * right.n;
	result.d = left.d * right.d;
	return result;
}
Rational operator /(Rational&left, Rational&right)
{
	Rational result(0, 0);
	result.n = left.n * right.d;
	result.d = left.d * right.n;
	return result;
}
bool operator == (Rational&left, Rational&right)
{
	Rational result(0, 0);
	for (int i = 1;; ++i)
	{
		for (int j = 1; left.d*i >= right.d*j; ++j)
		{
			if (left.d*i == right.d*j)
			{
				return (left.n == right.n);
			}
		}
	}
}

