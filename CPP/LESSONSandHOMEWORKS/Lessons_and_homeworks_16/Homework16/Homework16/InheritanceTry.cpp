
#include "pch.h"
#include <iostream>
using namespace std;

class A
{
public:
	int A_publ = 10;
	friend int main();
protected:
	int A_prot = 20;
private:
	int A_priv = 100;

};

class B : private A
{
public:

	int B_publ = 10;
protected:
	int B_prot = 20;
private:
	int B_priv = 100;
};

class C : protected B
{
public:
	int C_publ = 10;
	friend int main();
};

int main()
{
	C cC;
	B bB;
	cout << cC.A_publ << endl
		<< cC.A_prot << endl
		<< cC.A_priv << endl
		<< bB.A_publ << endl
		<< bB.A_prot << endl
		<< bB.A_priv << endl
		<< cC.B_publ << endl
		<< cC.B_prot << endl
		<< cC. << endl
		;
}