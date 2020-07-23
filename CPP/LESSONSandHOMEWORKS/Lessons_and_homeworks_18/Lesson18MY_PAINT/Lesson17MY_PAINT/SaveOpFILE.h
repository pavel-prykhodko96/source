#pragma once
#include "stdafx.h"
#include "vector_shape.h"
#include "Rectangle.h"
#include "Circle.h"

class SaveOpFILE
{
public:
	SaveOpFILE(/*const std::string &name*/);
	void save(vector_shape &figures);
	void open(vector_shape &figures);
	~SaveOpFILE();
	FILE *m_pFile = nullptr;
};
