#pragma once
#include "stdafx.h"
#include "vector_shape.h"
#include "Rectangle.h"
#include "Circle.h"

enum ShapeID { id_c, id_r };

struct BlockShape
{	
	int ID;
	union
	{
		shp::Circle c;
		shp::Rectangle r;
	};
	BlockShape(ShapeID id, const shp::Circle cl) : ID(id), c(cl) {};
	BlockShape(ShapeID id, const shp::Rectangle rec) : ID(id), r(rec) {};
};

class SaveOpFILE
{
public:
	SaveOpFILE(/*const std::string &name*/);
	void save(vector_shape &figures);
	void open(vector_shape &figures);
	~SaveOpFILE();
	FILE *m_pFile = nullptr;
};


