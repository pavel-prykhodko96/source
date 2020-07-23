
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	string iname = "1.txt";
	fstream ifs(iname, ios_base::in);

	vector <double> values;
	double value;
	char ch;
	while (ifs >> ch)
	{
		if (isdigit(ch))
		{
			ifs.putback(ch);
			ifs >> value;
			values.push_back(value);
		}
	}
	
	sort(values);
	int how_many(1);

	string oname = "v1.txt";
	fstream ofs(oname, ios_base::out);

	for (int i = 0; i < values.size() - 1; ++i)
	{
		if (values[i] != values[i+1])
		{
			ofs << values[i];
			if (how_many > 1)
			{
				ofs << " met " << how_many << " times.";
				how_many = 1;
			}
			ofs << endl;
		}
		else
		{
			++how_many;
		}
	}
	if (values[values.size() - 1] != values[values.size() - 2])
		ofs << values[values.size() - 1] << endl;
}