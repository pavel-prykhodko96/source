#pragma once
#include "stdafx.h"
#include "Shape.h"
//using namespace shp;

class vector_shape : public std::vector <shp::Shape*>
{
public:
	~vector_shape()
	{
		size_t Size = size();
		if (Size > 0) 
		{
			auto pData = data();
			for (int i = 0; i < Size; ++i)
				delete *(pData + i);
		}
	}
};