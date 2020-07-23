
/*��������� ��������� �����-������ �� ������� 11.3.2 �� ���: ���� 
��������� ����� ������������ ������� ��������� ���� � ��������. 
� ������ ��������� �������� ���� � ����������� ��� � ���������. 
������������� ��� ���������, ��������� ��������� ����� �� � ����� 
�������������� � �������� ���� � �������*/

#include "pch.h"
#include "../../../std_lib_facilities.h"

int main()
{
	cout << "Enter please the name of the file: ";
	string name;
	cin >> name;
	ifstream ifs{ name,ios_base::binary };

	vector <int> v;

	if (!ifs) error("It' impossible to open for reading the file ", name);
	for (int x; ifs.read(as_bytes(x), sizeof(int));)
		v.push_back(x);

	ofstream ofs{ name };

	if (!ofs) error("It' impossible to open for writing the file ", name);

	for (int x : v)
		ofs << x << " ";
		
	return 0;
}