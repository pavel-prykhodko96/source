
#include "pch.h"
#include "../../../std_lib_facilities.h"

//Read .txt file and write data to new file in low registr


int main()
try{
	string iname;
	cin >> iname;
	fstream ifs(iname, ios_base::in);
	if (!ifs) error("Can't open file ", iname);

	string oname;
	cin >> oname;
	fstream ofs(oname, ios_base::out);
	if (!ofs) error("Can't open file ", oname);

	for (char ch; ifs.get(ch);)
	{
		if (isalpha(ch)) ch = tolower(ch);
		ofs << ch;
	}

}
catch (runtime_error & e)
{
	cerr << e.what();
	cout << ", try again!\n";
	main();
}