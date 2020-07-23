#pragma once


class A
{
private:
	int m_a;
	static int m_nStatVar;
public:
	A(int n);
	A();
	~A();
	static int m_nCountObj;
	static int getStatVar();
};

