
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

void sort_by_name_surname(Student* Stud, int SIZE);
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
	sort_by_name_surname(studBase, SIZE);
	print_(studBase, SIZE);
}
void sort_by_name_surname(Student* Stud, int SIZE)
{
	Student temp;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE - 1 - i; ++j)
			if (strcmp(Stud[j].m_sSurname, Stud[j + 1].m_sSurname) > 0 || 
				(strcmp(Stud[j].m_sSurname, Stud[j + 1].m_sSurname) == 0 && strcmp(Stud[j].m_sName, Stud[j + 1].m_sName) >= 0))
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

/*
#include "pch.h"
#include <iostream>
using namespace std;

void sortwords(char**pWords,int nSize)
{
	char *pTemp;
	for (int i=0;i<nSize;++i)
	for (int j = 0; j < nSize - 1 - i; ++j)
	{
		if (_stricmp(pWords[j], pWords[j + 1]) > 0)
		{
			pTemp = pWords[j];
			pWords[j] = pWords[j + 1];
			pWords[j + 1] = pTemp;
		}
	}
}
int main()
{
	int nSize(100), ind(0), length(0), longhest(0);        //nSize for creating dynamic array
	char sStr[] = "ABC ZXY FGH ZKD PRI LEFT NICE_STARt Beautiful day acceptance accomodation fortunatelly";
	char **pWords = new char*[nSize], *pContext = nullptr; //Array of pointers         
	char *pWord = strtok_s(sStr, " ,:;!.?", &pContext);    //Just pointer to first word in sStr
	char *pLonghest (0);                                   //Assignment just for right compilation
	while (pWord != nullptr)
	{
		pWords[ind++] = pWord;                             //Array of pointers[member] = pointer to word
		nSize = ind;                                       //nSize = current size of pWords
		pWord = strtok_s(nullptr, " ,:;!.?", &pContext);   //Pointer = point to the next word in the sStr
	}
	sortwords(pWords, nSize);
	for (int i = 0; i < nSize; ++i)
	{
		length = strlen(pWords[i]);
		if (length > longhest) 
		{ 
			longhest = length; 
			pLonghest = pWords[i]; 
		}
	}
	cout << "Longhest word is: " << pLonghest << endl
		<< "There is " << nSize << " words" << endl;
	for (int i = 0; i < nSize; ++i)
	{
		cout << pWords[i] << " ";                          //Print words from pointer to \0 (like printing the common string)
	}
}
*/
