#include "stdafx.h"
#include "DisplayOutput.h"


DisplayOutput::DisplayOutput(HDC& hdc) : m_hdc(hdc) {}

DisplayOutput::~DisplayOutput() {}

void DisplayOutput::OutData(const VectorShape& vshp)
{
	if (!vshp.empty()) //old version of redrawing
	{
		for (auto pShape : vshp)
			pShape->draw(m_hdc);
	}
}