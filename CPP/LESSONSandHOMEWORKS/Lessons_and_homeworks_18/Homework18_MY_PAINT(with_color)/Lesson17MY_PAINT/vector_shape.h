#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "BaseOutput.h"
//using namespace shp;

class BaseOutput;

class VectorShape : public std::vector <shp::Shape*>
{
public:
	~VectorShape();
	void set_object(BaseOutput* B);
	void out_data();
private:
	BaseOutput *m_pOut = nullptr;
};