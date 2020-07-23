#include "pch.h"
#include <iostream>
#include <Windows.h>
#include "movingRectangle.h"
#include "Another_class.h"
#include "sum.h"

using namespace std;

class Child : public Base
{
public:
	Child() { cout << "this is the child constuctor\n"; }
};
class Base;
int main()
{
#pragma comment (lib, "MOVINGRECTANGLE.lib") //pragma comment
	//is needed for include lib, lib is direction to find 
#pragma comment (lib, "SUM.lib")

	Child c;
	Another_class ac;
	cout << "Enter size for rectangle: ";
	
	size_t rectSize;
	cin >> rectSize;
	movingSquare(sum(rectSize,0));
}
