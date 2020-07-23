#include "pch.h"
#include "FileFactory.h"


FileFactory::FileFactory()
{
	cout << "FileFactory constructor!\n";
}


FileFactory::~FileFactory()
{
}

BaseLoader* FileFactory::get_loader()
{
	return new FileLoader;
}