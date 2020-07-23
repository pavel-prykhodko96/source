
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	char ch;
	while (cin.get(ch))
	{
		if (isspace(ch)) cout << ch << " isspace \n";
		if (isalpha(ch)) cout << ch << " isalpha \n";
		if (isdigit(ch)) cout << ch << " isdigit \n";
		if (isxdigit(ch)) cout << ch << " isxdigit \n";
		if (iscntrl(ch)) cout << ch << " iscntrl \n";
		if (ispunct(ch)) cout << ch << " ispunct \n";
	}
}