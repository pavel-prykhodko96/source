
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	string name;
	cin >> name;
	ifstream ifs(name);

	vector <char> symbols;
	char ch;
	while (!ifs.eof()) {
		ifs.get(ch);
		switch (ch) {
		case 'a': case 'e': case 'i':
		case 'o': case 'u': case 'y':
			break;
		default:
			symbols.push_back(ch);
		}
	}

	ofstream ofs(name);
	for (char symb : symbols) {
		ofs << symb;
	}

	return 0;
}