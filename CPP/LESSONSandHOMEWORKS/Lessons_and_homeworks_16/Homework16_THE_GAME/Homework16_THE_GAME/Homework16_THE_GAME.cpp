
/*Д.З.написать игру(на почте) в консоли, использовать двумерный массив
или вектор, задать шарики - преграды рандомно, прийти к точке самым оптимальным
способом выбрать точку в которую шарику переместиться.*/

/*
1. Variables to input: row count, column count, starting point (x,y)
   destination point. 
2. Map based on those variables
3. Randomly located balls
4. Steps indicated by U D L R, last cell of a path is F
5. Number of steps
*/
#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

const char EMPTYSPACE = '_';
const char BALL = '0';
const int VERYHIGHVALUE = 10000000;

class Point //To set points on the map
{
public:
	Point(int y, int x) : m_y(y), m_x(x) {}
	friend class Game; //????
	friend class Map; //????
private:
	int m_y;
	int m_x;
};

class Map //To create Map and work with it
{
public:
	Map(int rows, int columns);	
	~Map();
	Map operator =(Map right);
	friend class Game;  //????
	void put(/*Point p,*/ char ch); //set Start Finish Balls Up Down Left Right 
	void show();
private:
	char **m_pTable;
	int m_nRows;
	int m_nColumns;
};
Map::Map(int rows,int columns) :m_nRows(rows), m_nColumns(columns)
{
	m_pTable = new char *[m_nRows];            //y
	for (int i = 0; i < m_nRows; ++i)
		m_pTable[i] = new char[m_nColumns];    //x
	for (int i = 0; i < m_nRows; ++i)          //y
		for (int j = 0; j < m_nColumns; ++j)   //x
			m_pTable[i][j] = EMPTYSPACE;       //[y][x]
}
Map::~Map()
{
	for (int i = 0; i < m_nRows; ++i)
		delete[] m_pTable[i];
	delete[] m_pTable;
}
Map Map::operator=(Map right)
{
	int m_nRows = right.m_nRows;
	int m_nColumns = right.m_nColumns;
	m_pTable = new char *[m_nRows];                 //y
	for (int i = 0; i < m_nRows; ++i)
		m_pTable[i] = new char[m_nColumns];         //x
	for (int i = 0; i < m_nRows; ++i)               //y
		for (int j = 0; j < m_nColumns; ++j)        //x
			m_pTable[i][j] = right.m_pTable[i][j];  //[y][x]
}
void Map::show()
{
	for (int i = 0; i < m_nRows; ++i)       //y
	{
		for (int j = 0; j < m_nColumns; ++j) //x
			cout << m_pTable[i][j] << ' ';   //[y][x]
		cout << endl;
	}
}

class Game //Logic of the game and work with map
{
public:
	Game(const Point& start,const Point& finish,
		const int& row, const int& col)
		: m_pStart(start),m_pFinish(finish), 
		m_nRow(row), m_nColumn(col)
	{
		pTable = new char *[m_nRow];           //y
		for (int i = 0; i < m_nRow; ++i)
			pTable[i] = new char[m_nColumn];   //x
		for (int i = 0; i < m_nRow; ++i)       //y
			for (int j = 0; j < m_nColumn;++j) //x
				pTable[i][j] = EMPTYSPACE;     //[y][x]
		
		if (start.m_x < m_nColumn&&start.m_y < m_nRow)
			pTable[start.m_y][start.m_x] = 'S';
		else cout << "Start point is out of frame" << endl;
		if (finish.m_x < m_nColumn&&finish.m_y < m_nRow)
			pTable[finish.m_y][finish.m_x] = 'F';
		else cout << "Finish point is out of frame" << endl;
		add_balls();
		find_path();
	}
	~Game()
	{
		for (int i = 0; i < m_nRow; ++i)
			delete[] pTable[i];
		delete[] pTable;
	}
	void show_map()
	{
		for (int i = 0; i < m_nRow; ++i)       //y
		{
			for (int j = 0; j < m_nColumn;++j) //x
				cout << pTable[i][j] << ' ';   //[y][x]
			cout << endl;
		}
	}
	void show_result()
	{
		for (int i = 0; i < m_nRow; ++i)       //y
		{
			for (int j = 0; j < m_nColumn; ++j) //x
				cout << pTableWithPath[i][j] << ' ';   //[y][x]
			cout << endl;
		}
		if (m_nTurnsAmount!=VERYHIGHVALUE)
		cout << m_nTurnsAmount << " - amount of turns" << endl;
		else cout << "There is no path to get 'F'" << endl;
	}
private:
	void add_balls();
	void find_path();
	Point m_pStart;
	Point m_pFinish;
	int m_nRow;
	int m_nColumn;
	int m_nTurnsAmount = VERYHIGHVALUE;
	char **pTable;
	char **pTableWithPath;
};
void Game::add_balls()
{
	int nBallsAmount = m_nRow * m_nColumn / 5;
	Point p(0, 0);
	srand(time(0));
	for (int i = 0; i < nBallsAmount; ++i)
	{
		p.m_x = rand() % (m_nColumn);
		p.m_y = rand() % (m_nRow);
		if (pTable[p.m_y][p.m_x] == EMPTYSPACE)  //[y][x]
			pTable[p.m_y][p.m_x] = BALL;         //[y][x]
		else --i;
	}
}
void Game::find_path()
{
	static const char cDirect[4] = { 'R','L','D','U' };
	static Point pCurPosit(m_pStart);
	static int nTurns(0);

	for (int i = 1, iter = 0; iter < 4; i *= -1, ++iter)
	{
		if (iter < 2)pCurPosit.m_x += i; //+-x
		else pCurPosit.m_y += i;         //+-y

		if (pCurPosit.m_x >= 0 && pCurPosit.m_x < m_nColumn //[y][x]
			&&pCurPosit.m_y >= 0 && pCurPosit.m_y < m_nRow)
		{
			if (pTable[pCurPosit.m_y][pCurPosit.m_x] == 'F')
			{
				if (nTurns < m_nTurnsAmount)
				{
					m_nTurnsAmount = nTurns;
					pTableWithPath = new char *[m_nRow];        //y
					for (int i = 0; i < m_nRow; ++i)
						pTableWithPath[i] = new char[m_nColumn];//x
					for (int i = 0; i < m_nRow; ++i)            //y
						for (int j = 0; j < m_nColumn; ++j)     //x
							pTableWithPath[i][j] = pTable[i][j];//[y][x]
				}
			}
			else if (pTable[pCurPosit.m_y][pCurPosit.m_x] == EMPTYSPACE)
			{
				
				pTable[pCurPosit.m_y][pCurPosit.m_x] = cDirect[iter];
				++nTurns;
				find_path();
				--nTurns;
				pTable[pCurPosit.m_y][pCurPosit.m_x] = EMPTYSPACE;
			}
		}
		if (iter < 2) pCurPosit.m_x -= i;
		else pCurPosit.m_y -= i;
	}
}


int main()
{
	const int ROWS = 6;
	const int COLUMNS = 6;
	Point st(0, 0), fn(3, 3);     //[y][x]
	Game mp(st, fn,ROWS,COLUMNS); //[y][x]
	mp.show_map();
	cout << endl;
	mp.show_result();
}

