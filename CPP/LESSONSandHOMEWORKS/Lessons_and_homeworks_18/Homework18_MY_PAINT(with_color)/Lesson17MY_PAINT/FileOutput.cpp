#include "stdafx.h"
#include "FileOutput.h"


FileOutput::FileOutput(char *cName) :m_cName(cName) {}

FileOutput::~FileOutput() {}

void FileOutput::OutData(const VectorShape& vshp)
{
	SaveOpFile SOF(m_cName);
	SOF.save(vshp);
}