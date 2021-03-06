
#include "pch.h"
#include "Singleton.h"


class B
{
public:
	B(int n) : m_CONSTVAR(n) {};
	B & operator = (const B & R);
	void show() { cout << m_CONSTVAR << endl; }
private:
	const int m_CONSTVAR;
	int m_b;
};

B & B::operator = (const B&R)
{
	if (this != &R)
	{
		int sizeB = sizeof(B);
		char *pBuff = new char[sizeB];
		B temp(R);
		memcpy(pBuff, this, sizeB);
		memcpy(this, &R, sizeB);
		memcpy(&temp, pBuff, sizeB);
		delete[]pBuff;
	}
	return *this;
}

int main()
{
	/*B a1(3), a2(10);
	a2 = a1;
	a2.show();
	return 0;*/
	Singleton a(7), b(5), c(11);
	c.show();
	b.show();
	a.show();
	return 0;
}
