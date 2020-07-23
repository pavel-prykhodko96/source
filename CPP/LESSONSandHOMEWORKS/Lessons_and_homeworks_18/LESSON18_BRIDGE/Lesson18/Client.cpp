#include "pch.h"
#include "Client.h"


Client::Client(int n): m_nNumber(n)
{
}
Client::~Client()
{
}
void Client::setMult(Mult* M)
{
	m_pMult = M;
}
int Client::multiplic()
{
	return m_pMult->multiplicF(m_nNumber);
}