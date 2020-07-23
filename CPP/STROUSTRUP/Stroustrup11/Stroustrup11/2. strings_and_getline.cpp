
#include "pch.h"
#include "../../../std_lib_facilities.h"

//out the strings with certain word
//with number of string

int main()
{
	string iname;
	cin >> iname;
	fstream ifs(iname, ios_base::in);

	int counter(0);
	string word;
	cin >> word;

	string data, cur_word;
	while (getline(ifs, data))
	{
		stringstream buffer(data);
		while (buffer >> cur_word)
		{
			if (cur_word == word)
			{
				cout << counter << ". " << data << endl;
				break;
			}
		}
		++counter;
	}
}