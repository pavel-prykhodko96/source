#pragma once
#include "BaseFactory.h"
#include "NetLoader.h"
class NetFactory : public BaseFactory
{
public:
	virtual BaseLoader* get_loader() override;
	NetFactory();
	~NetFactory();
};

