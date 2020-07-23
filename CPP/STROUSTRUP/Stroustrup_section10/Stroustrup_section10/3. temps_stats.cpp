
#include "pch.h"

int main()
{
	string iname = "raw_temps.txt";
	ifstream ist(iname);
	int hour(0);
	double temperature(0);
	char suffix('f');
	Reading temp;
	vector <Reading> temps;
	vector <double> temperatures;
	while (ist >> hour >> temperature >> suffix)
	{
		temp.hour = hour;
		temp.temperature = temperature;
		if ('c' == suffix) temperature = temperature * 9.0 / 5.0 + 32;
		temperatures.push_back(temperature);
		temps.push_back(temp);
	}
	double aver = 0;
	double median = 0;
	for (int i = 0; i < temps.size(); ++i)
	{
		aver += temps[i].temperature;
	}
	aver /= temps.size();
	sort(temperatures);
	median = temperatures[temps.size() / 2];
	if (temps.size() % 2 != 0)
	{
		median += temperatures[temps.size() / 2 + 1];
		median /= 2;
	}
	cout << endl << aver << endl << median;
}