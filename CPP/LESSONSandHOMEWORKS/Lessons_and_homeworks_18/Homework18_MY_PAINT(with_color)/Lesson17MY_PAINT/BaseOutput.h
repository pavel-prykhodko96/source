#pragma once
#include "vector_shape.h"

class VectorShape;


class BaseOutput
{
public:
	BaseOutput() {};
	~BaseOutput() {};
	virtual void OutData(const VectorShape& vshp) = 0;
private:
};
