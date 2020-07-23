
#include "pch.h"

int main()
{
	cout << "Enter the file name: ";
	string name;
	cin >> name;
	ifstream ist(name);
	int sum = 0, value = 0;
	while (ist >> value)
	{
		sum += value;
	}
	cout << "Sum is: " << sum << endl;
	return 0;
}