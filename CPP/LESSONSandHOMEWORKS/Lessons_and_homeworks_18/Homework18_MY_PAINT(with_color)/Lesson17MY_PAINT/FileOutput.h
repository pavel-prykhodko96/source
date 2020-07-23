#pragma once
#include "BaseOutput.h"
#include "SaveOpFILE.h"

class FileOutput : public BaseOutput
{
public:
	FileOutput(char *cName);
	~FileOutput();
	virtual void OutData(const VectorShape& vshp) override;
private:
	char *m_cName;
};