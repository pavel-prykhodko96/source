
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	string fname;
	cin >> fname;
	fstream fs(fname, ios_base::in);

	char symb;
	int allsymb(0), alpha(0), space(0), digit(0), xdigit(0),
		cntrl(0), punct(0), graph(0);
	while (fs.get(symb))
	{
		++allsymb;
		if (isalpha(symb)) ++alpha;
		if (isdigit(symb)) ++digit;
		if (isspace(symb)) ++space;
		if (isxdigit(symb)) ++xdigit;
		if (iscntrl(symb)) ++cntrl;
		if (ispunct(symb)) ++punct;
		if (isgraph(symb)) ++graph;
	}
	cout << "There are:\n"
		<< allsymb << " symbols in general\n"
		<< alpha << " letters\n"
		<< space << " spaces\n"
		<< digit << " digits\n"
		<< xdigit << " xdigits\n"
		<< cntrl << " cntrls\n"
		<< punct << " puncts\n"
		<< graph << " graphs\n";
	return 0;
}