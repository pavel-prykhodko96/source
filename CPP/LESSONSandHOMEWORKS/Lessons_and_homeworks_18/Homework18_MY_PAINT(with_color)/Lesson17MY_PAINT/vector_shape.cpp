#include "stdafx.h"
#include "vector_shape.h"

VectorShape::~VectorShape()
{
	size_t Size = size();
	if (Size > 0)
	{
		auto pData = data();
		for (int i = 0; i < Size; ++i)
			delete *(pData + i);
	}
}
void VectorShape::set_object(BaseOutput* B) { m_pOut = B; }
void VectorShape::out_data() { m_pOut->OutData(*this); }
