#include "stdafx.h"
#include "SaveOpFILE.h"

using namespace shp;

SaveOpFILE::SaveOpFILE(/*const std::string &name*/)
{

}
SaveOpFILE::~SaveOpFILE()
{

}
/*
enum ShapeID { id_c, id_r };

struct BlockShape
{
	int ID;
	union
	{
		shp::Circle c;
		shp::Rectangle r;
	};
	BlockShape(ShapeID id, Circle cl) : ID(id), c(cl) {};
	BlockShape(ShapeID id, shp::Rectangle rec) : ID(id), r(rec) {};
};
*/
const int CHARVECSIZE = 20;
void SaveOpFILE::save(vector_shape &figures)
{
	if (figures.size() > 0)
	{
		int nBsSize = sizeof(BlockShape);
		int nBuffSize = (figures.size() * nBsSize);
		char *cBuff = new char[nBuffSize];
		for (int i = 0; i < figures.size(); ++i)
		{
			if (figures[i]->m_name == "circ")
			{
				new (cBuff + i * nBsSize) BlockShape(id_c, *(static_cast<Circle*>(figures[i])));
			}
			else if (figures[i]->m_name == "rect")
			{
				new (cBuff + i * nBsSize) BlockShape(id_r, *(static_cast<shp::Rectangle*>(figures[i])));
			}
		}
		fopen_s(&m_pFile, "paint.dat", "wb");
		if (m_pFile != nullptr)
		{
			fwrite(cBuff, nBsSize, figures.size(), m_pFile);
			fclose(m_pFile);
		}
		delete[] cBuff;
	}
}
void SaveOpFILE::open(vector_shape &figures)
{
	fopen_s(&m_pFile, "paint.dat", "rb");
	if (m_pFile != nullptr)
	{
		fseek(m_pFile, 0L, SEEK_END);
		size_t fileSize = ftell(m_pFile);
		fseek(m_pFile, 0L, SEEK_SET);
		char *pBuff = new char[fileSize];
		size_t readDataSize = fread_s(pBuff, fileSize, sizeof(char), fileSize, m_pFile);
		if (readDataSize == fileSize)
		{
			int nCountShapes = fileSize / sizeof(BlockShape);
			BlockShape *pNextShape = (BlockShape*)pBuff;
			for (int i = 0; i < nCountShapes; ++i)
			{
				switch (pNextShape->ID)
				{
				case id_c:
					figures.push_back(new shp::Circle(pNextShape->c));
					break;
				case id_r:
					figures.push_back(new shp::Rectangle(pNextShape->r));
					break;
				}
				++pNextShape;
			}
		}
		delete[] pBuff;
		fclose(m_pFile);
	}
}

