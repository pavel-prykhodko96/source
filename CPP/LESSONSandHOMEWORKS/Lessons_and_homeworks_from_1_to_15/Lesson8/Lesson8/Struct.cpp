
#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

struct Point
{
	int m_nX;
	int m_nY;
};
struct Mother_board
{
	char m_sName[25];
	int m_nUsbPorts;
};
struct Comp
{
	char m_sHardName[25];
	int m_nHardVolume;
	Mother_board m_mothBoard; //Mother_board * m_mothBoard
};
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

void showarray(Student* Students, int Size);
void stud_sort_surname(Student* Stud, int SIZE);
void stud_sort_ages(Student* Stud, int SIZE);
void print_by_surnam(Student* Stud, int SIZE);

int main()
{
	const int SIZE = 5;
	int indS(0), indF(0);
	srand(time(0));
	Student studBase[SIZE];
	const char* pSN[]  ={ "Ivanov", "Petrov", "Andreev" };
	const char* pFN[]  ={ "Oleg", "Pavel", "Egor" };
	for (int i = 0; i < SIZE; ++i)
	{
		indS = rand() % 3;
		indF = rand() % 3;
		strcpy_s(studBase[i].m_sSurname, pSN[indS]);
		strcpy_s(studBase[i].m_sName, pFN[indF]);
		studBase[i].m_nAver_score = 3 + rand() % 2 + rand()%10 * 0.1;
		studBase[i].m_nAge = 20 + rand() % 11;
	}
	print_by_surnam(studBase, SIZE);
	//showarray(studBase, SIZE);
	/*
	Point p1 = { 7,11 };
	cout << p1.m_nX << "  " << p1.m_nY << endl;
	Point*pP = &p1;
	pP=65;
	cout << p1.m_nX << "  " << p1.m_nY << endl;
	pP->m_nY = 4;
	cout << p1.m_nX << "  " << p1.m_nY << endl;
	return 0;
	*/
}

void showarray(Student* Students, int Size)
{
	for (int i = 0; i < Size; ++i)
		Students[i].show();
}
void stud_sort_surname(Student* Stud, int SIZE)
{
	Student temp;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE - 1 - i; ++j)
			if (strcmp(Stud[j].m_sSurname, Stud[j + 1].m_sSurname) > 0)
			{
				temp = Stud[j];
				Stud[j] = Stud[j + 1];
				Stud[j + 1] = temp;
			}
}
void stud_sort_ages(Student* Stud, int SIZE)
{
	Student temp;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE - 1 - i; ++j)
			if (Stud[j].m_nAge > Stud[j + 1].m_nAge)
			{
				temp = Stud[j];
				Stud[j] = Stud[j + 1];
				Stud[j + 1] = temp;
			}
}
void print_by_surnam(Student* Stud, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
		if (Stud[i].m_sSurname[0] == 'A')
			cout << Stud[i].m_sSurname << " " << Stud[i].m_sName << " "
			<< Stud[i].m_nAge << " " << Stud[i].m_nAver_score << endl;
}