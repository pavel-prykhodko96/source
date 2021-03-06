
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
void print_(Student* Stud, int SIZE);
errno_t write_data_to_file(Student* Stud, int BaseSize);
errno_t read_data_from_file();
errno_t add_new_student();
void correct_string(Student *Stud, int SIZE);
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
	}
	write_data_to_file(studBase, SIZE);
	read_data_from_file();
	return 0;
}
void print_(Student* Stud, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
		cout << Stud[i].m_sSurname << " " << Stud[i].m_sName << " "
		<< Stud[i].m_nAge << " " << Stud[i].m_nAver_score << endl;
}
errno_t write_data_to_file(Student* Stud, int BaseSize)
{
	
	FILE *pFile = nullptr;
	errno_t err = fopen_s(&pFile, "Students1.txt", "wb");
	if (pFile != nullptr)
	{
		fwrite(Stud, sizeof(Student), BaseSize, pFile);
		fclose(pFile);
	}
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
		int DATA_SIZE = lFSize/sizeof(Student);
		Student* data = new Student[DATA_SIZE];
		//memset(data, NULL, DATA_SIZE);
		fseek(pFile, 0L, SEEK_SET);
		fread_s(data, lFSize, sizeof(char), lFSize, pFile); // or: fread_s(data, lFSize, sizeof(Student), DATA_SIZE, pFile);
		print_(data, DATA_SIZE);
		delete[]data;
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
		fwrite(&S, sizeof(char), strlen(data), pFile);
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
	Student S;
	cout << "Please enter Surname, Name, Age, Average Score of new student:\n";
	cin >> S.m_sSurname >> S.m_sName >> S.m_nAge >> S.m_nAver_score;
	Stud[num] = S;
	write_data_to_file(Stud, SIZE);
	return;
}