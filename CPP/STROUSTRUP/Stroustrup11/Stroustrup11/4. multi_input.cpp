
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	char ch_prim;
	char ch_sec;
	char notation;
	vector <int> values;
	vector <char> notations;
	int value(0);
	while (cin >> ch_prim)
	{
		if (ch_prim >= '1' && ch_prim <= '9')
		{
			cin.unget();
			notation = 'd';
			cin >> dec >> value;
		}
		else if (ch_prim == '0')
		{
			cin >> ch_sec;
			if (ch_sec == 'x')
			{
				cin >> hex >> value;
				notation = 'h';
			}
			else if (ch_sec >= '1' && ch_sec <= '9')
			{
				cin.unget();
				cin >> oct >> value;
				notation = 'o';
			}
		}
		else break;
		values.push_back(value);
		notations.push_back(notation);
	}
	for (int i = 0; i < values.size(); ++i)
	{
		cout << showbase << dec;
		if (notations[i] == 'h') cout << hex;
		else if (notations[i] == 'o') cout << oct;
		cout << setw(8) << values[i] 
			<< setw(3) << notations[i] << " turns to d " 
			<< setw(7) << dec << values[i] << endl;
	}
}