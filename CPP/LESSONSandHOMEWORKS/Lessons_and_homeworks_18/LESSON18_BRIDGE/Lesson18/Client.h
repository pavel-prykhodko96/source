#pragma once
#include "Mult.h"
class Client
{
public:
	Client(int n);
	~Client();
	void setMult(Mult* M);
	int multiplic();
private:
	Mult* m_pMult;
	int m_nNumber;
};

