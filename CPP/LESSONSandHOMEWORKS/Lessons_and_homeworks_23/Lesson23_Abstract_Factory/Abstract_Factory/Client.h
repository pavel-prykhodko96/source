#pragma once
#include "BaseFactory.h"
#include "BaseLoader.h"
#include "NetFactory.h"
#include "FileFactory.h"
enum FACTORYID{NF,FF};
class Client
{
public:
	Client();
	~Client();
	BaseFactory* m_BaseFac;
	BaseLoader* m_BaseLoad;
	BaseFactory* get_factory(int id);
};

