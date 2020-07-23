#include "stdafx.h"
#include "SaveOpFILE.h"

using namespace shp;

SaveOpFILE::SaveOpFILE(/*const std::string &name*/)
{

}
SaveOpFILE::~SaveOpFILE()
{

}
void SaveOpFILE::save(vector_shape &figures)
{
	fopen_s(&m_pFile, "paint.dat", "wb");
	if (m_pFile != nullptr)
	{
		for (int i = 0; i < figures.size(); ++i)
		{
			if (figures[i]->m_name == "circ") 
			{
				fwrite("c", sizeof(char), 1, m_pFile);
				fwrite(figures[i], sizeof(char), sizeof(shp::Circle), m_pFile);
			}
			else if (figures[i]->m_name == "rect")
			{
				fwrite("r", sizeof(char), 1, m_pFile);
				fwrite(figures[i], sizeof(char), sizeof(shp::Rectangle), m_pFile);
			}
		}
		fclose(m_pFile);
	}
}
void SaveOpFILE::open(vector_shape &figures)
{
	fopen_s(&m_pFile, "paint.dat", "rb");
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
				Circle cir ("abc", { 0,0 }, 0);
				fread_s(&cir, sizeof(shp::Circle), sizeof(char), 
					sizeof(shp::Circle), m_pFile);
				
				figures.push_back(new Circle("circ", cir.getCNTR(), cir.getRAD()));
				memset(&cir, NULL, sizeof(shp::Circle)); //it deletes unknown data that 
				                                         //occures an error
				mark[0] = '0';
			}
			else if (mark[0] == 'r')
			{
				//error occurs after dustruction if fread_s takes place 
				//it may be connected with a table of virtual functions
				//solvation - using memset
				shp::Rectangle rec ("abc", { 0,0 }, { 0,0 });
				fread_s(&rec, sizeof(shp::Rectangle), sizeof(char), 
					sizeof(shp::Rectangle), m_pFile);

				figures.push_back(new shp::Rectangle("rect", rec.getLT(), rec.getRB()));
				memset(&rec, NULL, sizeof(shp::Rectangle)); //it deletes unknown data that 
				                                            //occures an error
				mark[0] = '0';
			}
			else break;
		}	
		fclose(m_pFile);
	}
}

