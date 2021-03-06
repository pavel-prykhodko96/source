#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HMODULE hMod = LoadLibraryA("MOVINGRECTANGLE.dll");
	if (NULL == hMod)
	{
		cout << "No library!\n";
		system("pause");
		return 0;
	}
	typedef void(*pF)(size_t); //typedef neede to order that pF
	                           //is a new type, it's function pointer
	pF func = (pF)GetProcAddress(hMod, "movingSquare"); //call the function
	                           //from dll by calling our created new function
	cout << "Enter size for rectangle: ";
	size_t rectSize;
	cin >> rectSize;
	func(rectSize);
}
