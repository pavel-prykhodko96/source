
#include "pch.h"
/*
Create file with data in type Reading
from 10.5, enter 50+ values of temperature
into this, file name: raw_temps.txt
*/

int main()
{
	const char centig = 'c';
	const char faring = 'f';
	string oname;
	cout << "Please enter the file name for results: ";
	cin >> oname;
	ofstream ost(oname);
	cout << "Please enter the hour, temperature" 
		<< "and scale symbol 'c' or 'f':\n";
	Reading temp;
	char suffix;
	while (cin >> temp.hour >> temp.temperature >> suffix)
	{
		if (suffix != centig && suffix != faring)
			error("wrong temperature scale symbol: ", suffix);
		ost << temp.hour << " " <<  temp.temperature << suffix  << endl;
	}
}

/*int main()
{
	cout << "Enter the name of an input file: ";
	string iname;
	cin >> iname;
	ifstream ist(iname);
	if (!ist) error("Impossible to open the input file ", iname);

	cout << "Enter the name of an output file: ";
	string oname;
	cin >> oname;
	ofstream ost(oname);
	if (!ost) error("Impossible to open the output file ", oname);

	vector <Reading> temps;
	int hour;
	double temperature;
	while (ist >> hour >> temperature)
	{
		if (hour < 0 || 23 < hour) error("Incorrect time");
		temps.push_back(Reading{ hour,temperature });
	}
	for (int i = 0; i < temps.size(); ++i)
	{
		ost << '(' << temps[i].hour << ','
			<< temps[i].temperature << ")\n";
	}
	return 0;
}*/

