
#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void coutA(mutex* m)
{
	lock_guard<mutex> lock(*m);
	for (int i = 0; i < 100; ++i)
		cout << " a ";
	cout << endl;
}
void coutB(mutex* m)
{
	m->lock();
	for (int i = 0; i < 100; ++i)
		cout << " b ";
	cout << endl;
	m->unlock();
}
int main()
{
	mutex *mut = new mutex();

	thread a(coutA,mut);
	thread b(coutB,mut);

	if (a.joinable())
		a.join();
	if (b.joinable())
		b.join();
	delete mut;

	return 0;
}