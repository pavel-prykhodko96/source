
#include "pch.h"
#include <iostream>
#include "Client.h"
#include "Mult10.h"
#include "Mult100.h"
using namespace std;

int main()
{
	Mult10 objM10;
	Mult100 objM100;
	Client cl(5);
	cl.setMult(&objM10);
	cout << cl.multiplic() << endl;
	cl.setMult(&objM100);
	cout << cl.multiplic() << endl;
	return 0;
}

