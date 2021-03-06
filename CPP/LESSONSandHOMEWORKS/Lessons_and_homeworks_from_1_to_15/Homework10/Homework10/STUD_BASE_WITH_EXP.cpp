#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

struct Student
{
	char m_sName[25];
	char m_sSurname[25];
	double m_nAver_score;
	int m_nAge;
	int m_n_Exp;
	char* m_p_Exp;
};
void print_(Student* Stud, int SIZE);
errno_t write_data_to_file_with_EXP(Student* Stud, int BaseSize);
errno_t read_data_from_file();
int main()
{
	const int SIZE = 20;
	int indS(0), indF(0);
	srand(time(0));
	Student studBase[SIZE];
	const char* pSN[] = { "Ivanoff", "Petroff", "Andreevich", "Novik", "Dunst", "Jameson", "Rabinovich", "Romanova", "Ryurik", "Cameron" };
	const char* pFN[] = { "Charlote", "Pavel", "Egor", "John", "Rapuncel'", "Jora", "David", "Louis", "Dasha", "Zina" };
	for (int i = 0; i < SIZE; ++i)
	{
		indS = rand() % 10;
		indF = rand() % 10;
		strcpy_s(studBase[i].m_sSurname, pSN[indS]);
		strcpy_s(studBase[i].m_sName, pFN[indF]);
		studBase[i].m_nAver_score = 3 + rand() % 2 + rand() % 10 * 0.1;
		studBase[i].m_nAge = 20 + rand() % 11;
		studBase[i].m_n_Exp = rand() % 50;
		studBase[i].m_p_Exp = new char[studBase[i].m_n_Exp];
		for (int j = 0; j < studBase[i].m_n_Exp; ++j)  //STRCPY (SIZE + I) FOR \0
		{
			studBase[i].m_p_Exp[j] = char(studBase[i].m_n_Exp + j + 'A');
		}
	}
	write_data_to_file_with_EXP(studBase, SIZE);
	print_(studBase, SIZE);
	read_data_from_file();
	return 0;
}
void print_(Student* Stud, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		cout << Stud[i].m_sSurname << " " << Stud[i].m_sName << " "
			<< Stud[i].m_nAge << " " << Stud[i].m_nAver_score << endl;
		for (int j = 0; j < Stud[i].m_n_Exp; ++j)
			cout << Stud[i].m_p_Exp[j];
		cout << endl;
	}

}
errno_t write_data_to_file_with_EXP(Student* Stud, int BaseSize)
{
	int how_much_symb = 8;
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, "Students1.txt", "wb");
	for (int i = 0; i < BaseSize; ++i)
	{
		if (pFile != nullptr)
		{
			fwrite(Stud+i, sizeof(char), sizeof(Student), pFile);
			fwrite(Stud[i].m_p_Exp, sizeof(char), Stud[i].m_n_Exp, pFile);
		}
	}
	fclose(pFile);
	return err;
}
errno_t read_data_from_file()
{
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, "Students1.txt", "rb");
	if (pFile != nullptr)
	{
		fseek(pFile, 0L, SEEK_END);
		long lFSize = ftell(pFile);
		int element_count = 0;
		int DATA_SIZE = 0;
		Student data[100];
		fseek(pFile, 0L, SEEK_SET);
		for (int i = 0; element_count<lFSize; ++i)
		{
			++DATA_SIZE;
			fread_s(data+i, sizeof(Student)*sizeof(char), sizeof(char), sizeof(Student), pFile);
			data[i].m_p_Exp = new char[data[i].m_n_Exp];
			fread_s(data[i].m_p_Exp, data[i].m_n_Exp, sizeof(char), data[i].m_n_Exp, pFile);
			element_count += sizeof(Student) + data[i].m_n_Exp;
		}
		print_(data, DATA_SIZE);
		fclose(pFile);
	}
	return err;
}
