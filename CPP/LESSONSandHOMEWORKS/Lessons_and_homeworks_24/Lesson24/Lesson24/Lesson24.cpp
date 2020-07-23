#include "pch.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "count param: " << argc << endl;
	for (int i = 0; i<argc;++i)
		cout << argv[i] << endl;
	if (argc > 1 && strlen(argv[1]) == 2)
	{
		switch (argv[1][1])
		{
		case 's':
			cout << "as server\n";
			break;
		case 'c':
			cout << "as client\n";
			break;
		}
	}
	return 0;
}
