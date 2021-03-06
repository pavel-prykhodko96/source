/*Д.З. В задании с потоками 
- работать с .xml
- обработка исключений (при использовании new 
и для других инструментов, которые вы решили 
использовать в своём коде, а они могут приводить к 
исключениям)*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
#include <exception>
#include <memory>
using namespace std;

const int MINIMALDIVIDER = 2; //Number is not a primary if it divides by 2 or higher val;

//Function check numbers from nLower to nHigher and check is it primary
//If it is primary it writes it to the vector nData
void FindPrimValues(int nLower, int nHigher, vector <int>* nData, mutex* mMut);

int main()
try {
	ifstream fInFile("intervals.xml");
	if (!fInFile.is_open()) throw runtime_error("File to read data isn't opened!");

	string sOutName = "ABCDEF.txt";
	ofstream fOutFile(sOutName);
	if (!fOutFile.is_open()) throw runtime_error("File to write data isn't opened!");

	int nLoVal = 0, nHiVal = 0;
	int nIsValRead = 0;
	mutex *mMut = new mutex;
	
	vector <int> nData;
	vector <thread*> tThreads;
	
	char ch = 0;
	string word;
	int val = 0;
	bool closefunc = false;
	while (fInFile.good())
	{
		fInFile >> ch;
		if (ch == '/') closefunc = true;
		else if (isalpha(ch))
		{
			while (isalpha(ch))
			{
				word += ch;
				fInFile >> ch;
			}
			if (word == "low")
			{
				word.clear();
				if (closefunc) closefunc = false;
				else
				{
					while (fInFile >> ch && !isdigit(ch));
					fInFile.unget();
					fInFile >> val;
					nLoVal = val;
					++nIsValRead;
				}
			}
			else if (word == "high")
			{
				word.clear();
				if (closefunc) closefunc = false;
				else
				{
					while (fInFile >> ch && !isdigit(ch));
					fInFile.unget();
					fInFile >> val;
					nHiVal = val;
					++nIsValRead;
				}
			}
			else word.clear();
		}
		if (nIsValRead == 2)
		{
			thread* pThr = new thread(FindPrimValues, nLoVal, nHiVal, &nData, mMut);
			tThreads.push_back(pThr);
			nIsValRead = 0;
		}
	}

	for (thread *t : tThreads)
		if (t->joinable())
			t->join();

	for (int i = 0; i < nData.size(); ++i)
		fOutFile << nData[i] << " ";
	
	for (thread *t : tThreads)
		delete t;
	delete mMut;

	return 0;
}
catch (runtime_error& err)
{
	cerr << err.what();
}
catch (...)
{
	cerr << "Something unexpected has happened!";
}

void FindPrimValues(int nLower, int nHigher, vector <int>* nData, mutex* mMut)
{
	bool bIsPrimary = true, bIsUnique = true;
	if (nLower > nHigher)
	{
		int temp = nLower;
		nLower = nHigher;
		nHigher = temp;
	}
	if (nLower < 0 || nHigher < 0)
		throw runtime_error("Values from diapason lower than 0!");
	for (double i = nLower; i <= nHigher; ++i) //select num
	{
		for (double j = MINIMALDIVIDER; j <= i / MINIMALDIVIDER; ++j) //select dividing num
		{                   //for example if we check number 100, diapason is [2,50], not higher
							//because to divide by nums from 51 to 99 hasn't sense 
			if (int(i / j) == double(i / j))
			{               //check if score 'i' is primary 
				bIsPrimary = false;
				break;
			}
		}
		if (bIsPrimary)
		{
			mMut->lock(); //Mutex is needed to not write values from different
					      //threads in the same place
			for (int k : *nData)
				if (k == i) bIsUnique = false;	
			if (bIsUnique) 
				nData->push_back(i); 
			bIsUnique = true;
			mMut->unlock();
		}
		bIsPrimary = true;
	}
}