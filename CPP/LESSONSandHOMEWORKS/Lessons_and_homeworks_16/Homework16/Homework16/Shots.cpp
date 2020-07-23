
/*
* применить лямбду для сортировки выстрелов вместо предикативной ф-ции
(статическая ф-ция нужна была чтобы сделать её членом класса к которой просто
получить доступ) - OK
* применить также partial_sort() для 3 элементов (чтобы вывести 3 самых
точных выстрела) - OK
* для sort в class Shot попробовать лямбду и функтор - OK
*/

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <ctime> 
#include <vector>

using namespace std;

const int WHOLE_RAD = 20;
const int BULLS_EYE_RAD = 5;

class Shot
{
public:
	
	Shot(const char* surname) : m_nSurname(surname)
	{
		m_x = rand() % (WHOLE_RAD * 2 + 1) - WHOLE_RAD; //[-20;+20]
		m_y = rand() % (WHOLE_RAD * 2 + 1) - WHOLE_RAD; //[-20;+20]
		m_nDistance = sqrt(m_x * m_x + m_y * m_y);
	}
	friend class ShotFunc;
	void print()
	{
		cout << "Surname: " << m_nSurname << "; coordinates: (" << m_x
			<< "," << m_y << "); distance: ";
		if (m_nDistance >= 20) cout << "Out of target!";
		else cout << m_nDistance;
		cout << endl;
	}
	double getdist() const { return m_nDistance; }
private:
	int m_x;
	int m_y;
	double m_nDistance;
	const char* m_nSurname;
};

class ShotFunc
{
public:
	bool operator() (const Shot&left, const Shot&right) 
	{
		return left.m_nDistance < right.m_nDistance;
	}
private:
};

int main()
{
	const int nVectSize = 50;
	const char* cSurnames[] = {"Snow", "Killer", "Prykhodko", "Armstrong",
		"Krasavchik", "Inteligent", "Stubborn", "Louis", "Smith", "Karnegi"};
	
	srand(time(0));
	vector <Shot> Shots;
	for (int i = 0; i < nVectSize; ++i)
		Shots.push_back(Shot(cSurnames[rand()%10]));
	
	auto itb = Shots.begin(), it = Shots.end();
	

	//Using Lambdas
	partial_sort(itb,itb+3, it, [](const Shot&left, const Shot&right)
	{//Only 3 elements will be located in right order
		return left.getdist() < right.getdist();
	});
	for (int i = 0; i < 3; ++i)
		Shots[i].print();

	//Using Functor
	ShotFunc FUNCTOR;
	sort(itb, it, FUNCTOR);
	for (int i = 0; i < 10; ++i)
		Shots[i].print();

	int nCounter(0);
	for (;;++itb)
	{
		itb = find_if(itb, it, [](const Shot& S)
		{
			return (S.getdist() < BULLS_EYE_RAD * 2);
		});
		if (itb != it) ++nCounter;
		else break;
	}
	cout << "Target percantage is " 
		<<(double)nCounter/nVectSize*100 << "%" << endl;
}

