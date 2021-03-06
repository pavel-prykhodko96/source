
#include "pch.h"
#include <iostream>

class A
{
public:
	const int m_Const;
	A(int n) : m_Const(5), m_a(n) {} // A (int n = 0) конструктор и по умолчанию 
						             // и принимающий значение
	A& operator=(const A& R) // прописываем оператор присваивания
							 // чтобы не было ошибки присвоения константы
	/*{
		this->~A();
		m_a = R.m_a;
		int *pA = const_cast<int*> (&m_Const); // создаём указатель который может
		*pA = R.m_Const;                       // менять данные по адресу где
											   // записана константа
		return *this;
	}*/
	{
		this->~A();               
		A *pA = new (this) A (R); //или с помощью placement new
		return *this;
	}
private:
	int m_a;
};

int main()
{
	A aObj(11);
	A a1Obj(8);
	aObj = a1Obj; // Error, нельзя присвоить значение константе
	A a2(a1Obj);
}
