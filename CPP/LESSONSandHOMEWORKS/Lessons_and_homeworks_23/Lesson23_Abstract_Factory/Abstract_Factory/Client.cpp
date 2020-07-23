#include "pch.h"
#include "Client.h"


Client::Client()
{
}
Client::~Client()
{
}
BaseFactory* Client::get_factory(int id)
{
	if (id == NF)
		m_BaseFac = new NetFactory;
	else if (id == FF)
		m_BaseFac = new FileFactory;
	m_BaseLoad = m_BaseFac->get_loader();
	return m_BaseFac;
}

