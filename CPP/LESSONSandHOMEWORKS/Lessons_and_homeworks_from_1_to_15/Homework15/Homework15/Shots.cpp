
/*
��������� �� ���������� <algorithm>
std::sort() � std::find_if() � ������������� �-��� ��� sort()
������ �� ��������� �������� ��������� �������� � ������
������ ���� ������� ������� �� ���������� �����, ������� ������� 
� ���������� ��������� �� ������ ������, ������� ����������� � ������������
������ ������ 20 �� (������), ����� ������ ����� � ������������ (0,0)
������������� 50 ��������� ������� ����� ��������� � ������� � 
��������� 
1) 3 ����� ������ ���������
2) ������� ��������� � "�������", ������ �������� 5 ��
���������: ������������ ������������� ����������� �-���.
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
	//Shot(int x=0, int y=0) : m_x(x), m_y(y)
	Shot(const char* surname) : m_nSurname(surname)
	{
		m_x = rand() % (WHOLE_RAD * 2 + 1) - WHOLE_RAD; //[-20;+20]
		m_y = rand() % (WHOLE_RAD * 2 + 1) - WHOLE_RAD; //[-20;+20]
		m_nDistance = sqrt(m_x * m_x + m_y * m_y);
	}
	friend bool cmp_dist(const Shot &left, const Shot &right);
	friend bool if_dist_lower_be(const Shot& S);
	void print()
	{
		cout << "Surname: " << m_nSurname << "; coordinates: (" << m_x
			<< "," << m_y << "); distance: ";
		if (m_nDistance >= 20) cout << "Out of target!";
		else cout << m_nDistance;
		cout << endl;
	}
private:
	int m_x;
	int m_y;
	double m_nDistance;
	const char* m_nSurname;
};
bool cmp_dist(const Shot &left, const Shot &right)
{
	if (left.m_nDistance < right.m_nDistance) return true;
	return false;
}
bool if_dist_lower_be(const Shot& S)
{
	if (S.m_nDistance < BULLS_EYE_RAD*2) return true;
	return false;
}
int main()
{
	const int nVectSize = 50;
	const char* cSurnames[] = { "Snow","Killer","Prykhodko", "Armstrong",
		"Krasavchik","Inteligent","Stubborn","Louis","Smith","Karnegi"};
	//10 surnames
	srand(time(0));
	vector <Shot> Shots;
	for (int i = 0; i < nVectSize; ++i)
		Shots.push_back(Shot(cSurnames[rand()%10]));
	
	//vector <Shot>::iterator itb = Shots.begin(), it = Shots.end();
	auto itb = Shots.begin(), it = Shots.end();
	sort(itb, it, cmp_dist);
	for (int i = 0; i < 3; ++i)
		Shots[i].print();

	int nCounter(0);
	for (;;++itb)
	{
		itb = find_if(itb, it, if_dist_lower_be);
		if (itb != it) ++nCounter;
		else break;
	}
	cout << "Target percantage is " 
		<<(double)nCounter/nVectSize*100 << "%" << endl;
}

