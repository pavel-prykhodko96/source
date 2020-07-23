
#include "pch.h"
#include <iostream>
#include "Line.h"

using namespace std;

int main()
{
	Line lMyLine(1, 3, 4, 643);
	cout << lMyLine.get_dist() << endl;
}