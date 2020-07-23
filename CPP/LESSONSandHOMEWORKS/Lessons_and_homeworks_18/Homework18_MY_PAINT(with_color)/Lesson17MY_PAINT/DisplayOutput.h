#pragma once
#include "BaseOutput.h"

class DisplayOutput : public BaseOutput
{
public:
	DisplayOutput(HDC& hdc);
	~DisplayOutput();
	virtual void OutData(const VectorShape& vshp) override;
private:
	HDC m_hdc;
};