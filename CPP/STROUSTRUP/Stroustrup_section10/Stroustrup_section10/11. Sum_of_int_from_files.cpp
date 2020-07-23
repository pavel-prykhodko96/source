
#include "pch.h"

int main()
{
	int sum = 0, cur_val = 0;
	string file_name;
	cin >> file_name;
	ifstream ist(file_name);
	char ch;
	while (ist.get(ch))
	{
		if (isdigit(ch))
		{
			ist.unget();
			ist >> cur_val;
			sum += cur_val;
		}
		if (ist.eof())
		{
			ist.close();
			break;
		}
	}
	cout << sum;
	return 0;
}