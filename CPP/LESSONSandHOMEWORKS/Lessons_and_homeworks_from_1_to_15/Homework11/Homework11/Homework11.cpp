
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

bool ascAGE(Student fir, Student sec)
{
	if (fir.m_nAge > sec.m_nAge) return true;
	return false;
}
bool descAGE(Student fir, Student sec)
{
	if (fir.m_nAge < sec.m_nAge) return true;
	return false;
}
bool ascSCORE(Student fir, Student sec)
{
	if (fir.m_nAver_score > sec.m_nAver_score) return true;
	return false;
}
bool descSCORE(Student fir, Student sec)
{
	if (fir.m_nAver_score < sec.m_nAver_score) return true;
	return false;
}
bool ascNAME(Student fir, Student sec)
{
	if (strcmp(fir.m_sName,sec.m_sName) > 0) return true;
	return false;
}
bool descNAME(Student fir, Student sec)
{
	if (strcmp(fir.m_sName, sec.m_sName) < 0) return true;
	return false;
}
bool ascSURNAME(Student fir, Student sec)
{
	if (strcmp(fir.m_sSurname, sec.m_sSurname) > 0) return true;
	return false;
}
bool descSURNAME(Student fir, Student sec)
{
	if (strcmp(fir.m_sSurname, sec.m_sSurname) < 0) return true;
	return false;
}
void sort_by_name_surname(Student* Stud, int SIZE, bool (*pSORT)(Student,Student));
void print_(Student* Stud, int SIZE);

int main()
{
	const int SIZE = 20;
	int indS(0), indF(0);
	srand(time(0));
	Student studBase[SIZE];
	const char* pSN[] = { "Ivanoff", "Petroff", "Andreevich", "Novik", "Dunst", "Jameson", "Rabinovich", "Romanova", "Ryurik", "Cameron" };
	const char* pFN[] = { "Charlote", "Pavel", "Egor", "John", "Rapuncel'", "Jopa", "David", "Louis", "Dasha", "Rita", "Zina" };
	for (int i = 0; i < SIZE; ++i)
	{
		indS = rand() % 10;
		indF = rand() % 11;
		strcpy_s(studBase[i].m_sSurname, pSN[indS]);
		strcpy_s(studBase[i].m_sName, pFN[indF]);
		studBase[i].m_nAver_score = 3 + rand() % 2 + rand() % 10 * 0.1;
		studBase[i].m_nAge = 20 + rand() % 11;
	}
	sort_by_name_surname(studBase, SIZE, ascAGE);
	sort_by_name_surname(studBase, SIZE, ascSCORE);
	sort_by_name_surname(studBase, SIZE, ascNAME);
	sort_by_name_surname(studBase, SIZE, ascSURNAME);
	print_(studBase, SIZE);
}
void sort_by_name_surname(Student* Stud, int SIZE, bool (*pSORT)(Student,Student))
{
	Student temp;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE - 1 - i; ++j)
			if (pSORT(Stud[j],Stud[j+1]))
			{
				temp = Stud[j];
				Stud[j] = Stud[j + 1];
				Stud[j + 1] = temp;
			}
}
void print_(Student* Stud, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
		cout << Stud[i].m_sSurname << " " << Stud[i].m_sName << " "
		<< Stud[i].m_nAge << " " << Stud[i].m_nAver_score << endl;
}
