#include "stdafx.h"
#include "SaveOpFILE.h"
using namespace shp;

SaveOpFile::SaveOpFile(char* cFileName)
{
	set_name(cFileName);
}
SaveOpFile::~SaveOpFile()
{

}
void SaveOpFile::save(const VectorShape &figures) 
{
	fopen_s(&m_pFile, m_FileName, "wb");
	if (m_pFile != nullptr)
	{
		for (int i = 0; i < figures.size(); ++i)
		{
			if (figures[i]->getName() == "circ")
			{
				fwrite("c", sizeof(char), 1, m_pFile);
				fwrite(figures[i], sizeof(char), sizeof(shp::Circle), m_pFile);
			}
			else if (figures[i]->getName() == "rect")
			{
				fwrite("r", sizeof(char), 1, m_pFile);
				fwrite(figures[i], sizeof(char), sizeof(shp::Rectangle), m_pFile);
			}
		}
		fclose(m_pFile);
	}
}
void SaveOpFile::open(VectorShape &figures)
{
	fopen_s(&m_pFile, m_FileName, "rb");
	if (m_pFile != nullptr)
	{
		figures.clear();
		
		char mark[] = "0";
		for (int i = 0; ; ++i)
		{
			fread_s(&mark, sizeof(char), sizeof(char), 1, m_pFile);
			if (mark[0] == 'c')
			{
				//error occurs after dustruction if fread_s takes place 
				//it may be connected with a table of virtual functions
				//solvation - using memset
				Circle cir("abc",0, { 0,0 }, 0);
				fread_s(&cir, sizeof(shp::Circle), sizeof(char),
					sizeof(shp::Circle), m_pFile);

				figures.push_back(new Circle("circ", cir.getRgb(), cir.getCNTR(), cir.getRAD()));
				memset(&cir, NULL, sizeof(shp::Circle)); //it deletes unknown data that 
														 //occures an error
				mark[0] = '0';
			}
			else if (mark[0] == 'r')
			{
				//error occurs after dustruction if fread_s takes place 
				//it may be connected with a table of virtual functions
				//solvation - using memset
				shp::Rectangle rec("abc",0, { 0,0 }, { 0,0 });
				fread_s(&rec, sizeof(shp::Rectangle), sizeof(char),
					sizeof(shp::Rectangle), m_pFile);

				figures.push_back(new shp::Rectangle("rect", rec.getRgb(), rec.getLT(), rec.getRB()));
				memset(&rec, NULL, sizeof(shp::Rectangle)); //it deletes unknown data that 
															//occures an error
				mark[0] = '0';
			}
			else break;
		}
		fclose(m_pFile);
	}
}
void SaveOpFile::set_name(char* cFileName)
{
	if (cFileName != 0)
		memcpy_s(m_FileName, 260, cFileName, 260);
}