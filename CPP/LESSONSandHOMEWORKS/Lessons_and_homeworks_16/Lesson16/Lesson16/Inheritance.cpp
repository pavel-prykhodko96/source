
#include "pch.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int n): m_protMemb(n),m_privMemb(n*n) 
	{ 
		cout << "creating Parent's type for " << this << endl;
	}
	~Parent() { cout << "destruction Parent's type for " << this << endl; }
	void show() { cout << "This is Parent's show function" << endl; }
protected:
	int m_protMemb;
private:
	int m_privMemb;
};

class Child : public Parent
{
public:
	Child(int n, int m) : Parent(n), m_prMem(m) 
	{	                                        
		cout << "creating Child's type for " << this << endl;
	}
	~Child() { cout << "destruction Child's type for " << this << endl; }
	void show() { cout << "This is Child's show function" << endl; }
	//эта ф-ция перекроет ф-цию show() Parent класса
private:
	int m_prMem;
};

int main()
{
	Child ch(7, 12);
	ch.show();
	ch.Parent::show();
	return 0;
}