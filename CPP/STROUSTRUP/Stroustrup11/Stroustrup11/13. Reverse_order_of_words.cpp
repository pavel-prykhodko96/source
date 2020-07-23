
#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	cout << "Please enter the name of file: ";
	string name_of_file;
	cin >> name_of_file;
	ifstream ifs(name_of_file);

	if (!ifs) error("File wasn't open, ", name_of_file);
	vector <string> words;
	string word;

	while (ifs >> word)
		words.push_back(word);

	ofstream ofs(name_of_file);
	if (!ofs) error("File wasn't open, ", name_of_file);

	for (int i = words.size() - 1; i >= 0; --i)
	{
		ofs << words[i] << " ";
	}
	return 0;
}