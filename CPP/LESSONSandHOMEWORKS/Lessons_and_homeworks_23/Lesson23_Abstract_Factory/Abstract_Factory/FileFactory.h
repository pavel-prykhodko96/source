#pragma once
#include "BaseFactory.h"
#include "FileLoader.h"
class FileFactory: public BaseFactory
{
public:
	virtual BaseLoader* get_loader() override;
	FileFactory();
	~FileFactory();
};

