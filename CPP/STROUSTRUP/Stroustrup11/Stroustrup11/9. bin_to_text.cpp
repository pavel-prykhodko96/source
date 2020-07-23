
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	cout << "Enter please the name of the file: ";
	string name;
	cin >> name;
	ifstream ifs{ name };

	vector <int> v;

	if (!ifs) error("It' impossible to open for reading the file ", name);
	for (int x; ifs >> x; )
		v.push_back(x);

	ofstream ofs{ name, ios_base::binary };

	if (!ofs) error("It' impossible to open for writing the file ", name);

	for (int x : v)
		ofs.write(as_bytes(x),sizeof(int));

	return 0;
}