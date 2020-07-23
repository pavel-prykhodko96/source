#pragma once
#include "stdafx.h"
#include "vector_shape.h"
#include "Rectangle.h"
#include "Circle.h"

class SaveOpFile
{
public:
	SaveOpFile(char* cFileName);
	~SaveOpFile();
	void save(const VectorShape &figures);
	void open(VectorShape &figures);
	void set_name(char* cFileName);
private:
	char m_FileName[260];// = "paint.dat"; //same size as in the main()
	FILE *m_pFile = nullptr;
};

