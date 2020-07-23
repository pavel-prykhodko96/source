#include "pch.h"
#include "NetFactory.h"


NetFactory::NetFactory()
{
	cout << "NetFactory constructor!\n";
}


NetFactory::~NetFactory()
{
}
BaseLoader* NetFactory::get_loader() 
{
	return new NetLoader;
}