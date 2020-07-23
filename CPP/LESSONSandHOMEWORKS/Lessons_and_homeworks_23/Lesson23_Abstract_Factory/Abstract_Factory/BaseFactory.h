#pragma once
#include "BaseLoader.h"
#include <iostream>
using std::cout;
class BaseFactory
{
public:
	virtual BaseLoader* get_loader() = 0;
	BaseFactory();
	~BaseFactory();
};

