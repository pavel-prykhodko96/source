

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
	void show()
	{
		cout << m_sSurname << " " << m_sName << " "
			<< m_nAge << " " << m_nAver_score << endl;
	}
};

errno_t write_data_to_file(Student* Stud, int BaseSize)
{
	const int DATA_SIZE = 10000;
	int count_of_symb = 0;
	char data[DATA_SIZE];
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, "Students.txt", "w");
	if (pFile != nullptr)
	{
		for (int i = 0; i < BaseSize; ++i)
		{
			count_of_symb += sprintf_s(data + count_of_symb, DATA_SIZE - count_of_symb,
				"%s  %s  %d  %f\n", Stud[i].m_sSurname, Stud[i].m_sName,
				Stud[i].m_nAge, Stud[i].m_nAver_score);
		}
		fwrite(data, sizeof(char), strlen(data), pFile);
		fclose(pFile);
	}
	return err;
}
errno_t read_data_from_file()
{
	const int DATA_SIZE = 10000;
	char data[DATA_SIZE];
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, "Students.txt", "r");
	if (pFile != nullptr)
	{
		fseek(pFile, 0L, SEEK_END);
		long lFSize = ftell(pFile);
		memset(data, NULL, DATA_SIZE);
		fseek(pFile, 0L, SEEK_SET);
		fread_s(data, lFSize + 1, sizeof(char), lFSize, pFile);
		cout << data;
		fclose(pFile);
	}
	return err;
}
errno_t add_new_student()
{
	char data[100];
	memset(data, NULL, 100);
	Student S;
	cout << "Please enter Surname, Name, Age, Average Score of new student:\n";
	cin >> S.m_sSurname >> S.m_sName >> S.m_nAge >> S.m_nAver_score;
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, "Students.txt", "a");
	if (pFile != nullptr)
	{
		sprintf_s(data, 100,
			"%s  %s  %d  %f\n", S.m_sSurname, S.m_sName,
			S.m_nAge, S.m_nAver_score);
		fwrite(data, sizeof(char), strlen(data), pFile);
		fclose(pFile);
	}
	return err;
}
void correct_string(Student *Stud, int SIZE)
{
	int num = 0;
	read_data_from_file();
	cout << "Please enter the number of string to correct: ";
	cin >> num;
	char data[100];
	memset(data, NULL, 100);
	Student S;
	cout << "Please enter Surname, Name, Age, Average Score of new student:\n";
	cin >> S.m_sSurname >> S.m_sName >> S.m_nAge >> S.m_nAver_score;
	Stud[num] = S;
	write_data_to_file(Stud, SIZE);
	return;
}
int main()
{
	const int SIZE = 20;
	int indS(0), indF(0);
	srand(time(0));
	Student studBase[SIZE];
	const char* pSN[] = { "Ivanoff", "Petroff", "Andreevich", "Novik", "Dunst", "Jameson", "Rabinovich", "Romanova", "Ryurik", "Cameron" };
	const char* pFN[] = { "Charlote", "Pavel", "Egor", "John", "Rapuncel'", "Jopa", "David", "Louis", "Dasha", "Zina" };
	for (int i = 0; i < SIZE; ++i)
	{
		indS = rand() % 10;
		indF = rand() % 10;
		strcpy_s(studBase[i].m_sSurname, pSN[indS]);
		strcpy_s(studBase[i].m_sName, pFN[indF]);
		studBase[i].m_nAver_score = 3 + rand() % 2 + rand() % 10 * 0.1;
		studBase[i].m_nAge = 20 + rand() % 11;
	}
	write_data_to_file(studBase, SIZE);
	correct_string(studBase, SIZE);
	read_data_from_file();
}
