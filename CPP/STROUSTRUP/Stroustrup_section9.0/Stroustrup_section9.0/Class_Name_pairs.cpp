
#include "pch.h"
#include "../../std_lib_facilities.h"


class Name_pairs
{
public:
	void read_names();
	void sort_all();
	vector <string> names;
	vector <double> ages;
private:
	const string stop_word = "stop";
	void read_ages();
	string name;
	double age;
	void sort_ages(vector <string>& names_copy,
		vector <double>& ages, double value, int index);
};
void Name_pairs::read_names()
{
	while (true)
	{
		cin >> name;
		if (name!=stop_word)
		names.push_back(name);
		else 
		{
			name = "";
			break;
		}
	}
	read_ages();
}
void Name_pairs::read_ages()
{
	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << " = ";
		cin >> age;
		ages.push_back(age);
	}
}
ostream& operator<<(ostream& os,const Name_pairs& np)
{
	for (int i=0;i<np.names.size();++i)
    os << np.names[i] << " = " << np.ages[i] << endl;
	return os;
}
bool operator ==(const Name_pairs& a, const Name_pairs& b)
{
	return a.ages == b.ages && a.names == b.names;
}
bool operator !=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}
void Name_pairs::sort_all()
{
	vector <string> names_copy;
	names_copy = names;
	sort(names.begin(), names.end());
	for (int i = 0; i < names_copy.size(); ++i)
	{
		sort_ages(names_copy, ages, ages[i], i);
	}
}
void Name_pairs::sort_ages(vector <string>& names_copy,
	vector <double>& ages, double value, int index)
{
	int temp = 0;
	for (int j = 0; j < names.size(); ++j)
	{
		if (names_copy[index] == names[j])
		{
			temp = ages[j];
			ages[j] = value;
			names_copy[index] = " ";
			sort_ages(names_copy, ages, temp, j);
		}
	}
}

int main()
try{
	Name_pairs var;
	var.read_names();
	var.sort_all();
	cout << var;
}
catch(runtime_error&e)
{
	cerr << e.what();
}