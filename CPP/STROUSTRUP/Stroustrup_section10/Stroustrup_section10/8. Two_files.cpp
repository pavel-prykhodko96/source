
#include "pch.h"

int main()
{
	string fir_name;
	string sec_name;
	cout << "Please enter two names of files!: ";
	cin >> fir_name >> sec_name;
	char c;
	ifstream ifs(fir_name);
	ofstream ofs("RESULT.txt");
	while (ifs.get(c))
	{
		ofs << c;
	}
	ifs.close();
	ifs.open(sec_name);
	while (ifs.get(c))
	{
		ofs << c;
	}
	return 0;

}