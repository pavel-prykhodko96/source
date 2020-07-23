
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	string iname = "val.txt";
	//cout << "Please enter the name of file to read values: ";
	//cin >> iname;
	fstream ifs (iname, ios_base::in);

	vector <double> values;
	double value;
	while (true)
	{
		ifs >> value;
		if (ifs.fail())
		{
			ifs.clear();
			continue;
		}
		if (ifs.eof()) break;
		if (ifs.bad())
		{
			cout << "Something went wrong!\n";
			break;
		}
		values.push_back(value);
	}

	string oname = "v.txt";
	//cout << "Please enter the name of file to write values: ";
	//cin >> oname;
	fstream ofs(oname, ios_base::out);

	ofs << scientific << setprecision(8);
	for (int i = 0; i < values.size(); ++i)
	{
		if (i % 4 == 0) ofs << endl;
		ofs  << setw(20) << values[i];
	}
}