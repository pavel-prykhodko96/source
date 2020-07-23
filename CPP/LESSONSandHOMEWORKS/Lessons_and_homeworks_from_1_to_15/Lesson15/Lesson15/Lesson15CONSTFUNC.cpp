#include "pch.h"
#include <iostream>
using namespace std;

class A
{
public:
	A(int n) : m_a(n) {}
	A operator+ (const A& R) const
	{
		A temp(m_a + R.m_a);
		return temp;
	}
	A & operator= (const A&R)
	{
		m_a = R.m_a;
		return *this;
	}
	void show() { cout << m_a << endl; }
private:
	int m_a;
};

int main()
{
	A ob1(7), ob2(12), ob3(6), ob4(44);
	const A ob5(555);
	return 0;
}