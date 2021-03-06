
#include "pch.h"
#include "sqlite3.h"
#include <iostream>
#include <vector>
#pragma comment(lib, "sqlite3.lib")

using namespace std;

//#define DB_CREATION 
//#define DB_WORK


#ifdef DB_WORK
struct AutorsData
{
	int m_id;
	std::string m_name;
};

static int callback(void *vecData, int argc, char **argv, char **azColName) {

	std::vector<AutorsData>* pData = (std::vector<AutorsData>*)vecData;
	AutorsData temp;
	for (int i = 0; i < argc; i++) {
		if (0 == strcmp(azColName[i], "AUT_ID"))
		{
			temp.m_id = atoi(argv[i]);
		}
		else if (0 == strcmp(azColName[i], "AUT_NAME"))
		{
			temp.m_name = argv[i];
		}
	}
	pData->push_back(temp);
	return 0;
}
#endif


int main()
{
	sqlite3* DB;
	int exit = 0;
	char* pMessaggeError;
	std::string sqlQuery;
	exit = sqlite3_open("library.db", &DB);

	if (exit) {
		std::cout << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return -1;
	}
	else
		std::cout << "The database was opened/created successfully!" << std::endl;

#ifdef DB_WORK
	//AutorsData dataFromQuery;
	std::vector<AutorsData> dataFromDB;
	sqlQuery = "SELECT * FROM Autors";
	exit = sqlite3_exec(DB, sqlQuery.c_str(), callback, &dataFromDB, &pMessaggeError);
	if (exit != SQLITE_OK) {
		std::cout << "Error data selection" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
	{
		std::cout << "data was selected Successfully" << std::endl;
		for (AutorsData aut : dataFromDB)
		{
			cout << aut.m_id << " " << aut.m_name.data() << endl;
		}
	}
#endif

#ifdef DB_CREATION
	sqlQuery = "CREATE TABLE Autors(AUT_ID INT PRIMARY KEY NOT NULL, AUT_NAME TEXT NOT NULL)";
	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);

	if (exit != SQLITE_OK) {
		std::cout << "Error Create Table" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Table created Successfully" << std::endl;

	sqlQuery = "INSERT INTO Autors VALUES(1, 'David Grann'); INSERT INTO Autors VALUES(2, 'Nikolay M Josuttis'); INSERT INTO Autors VALUES(3, 'Duglas Gregor'); INSERT INTO Autors VALUES(4, 'Alex Michaelides');";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Records created Successfully!" << std::endl;
	//create Publisher table
	sqlQuery = "CREATE TABLE Publisher(PB_ID INT PRIMARY KEY NOT NULL, PB_NAME CHAR(150))";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);

	if (exit != SQLITE_OK) {
		std::cout << "Error Create Publisher Table" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Table Publisher was created Successfully" << std::endl;

	sqlQuery = "INSERT INTO Publisher VALUES(1, 'Vintage'); INSERT INTO Publisher VALUES(2, 'Vintage Books'); INSERT INTO Publisher VALUES(3, 'Celadon Books'); INSERT INTO Publisher VALUES(4, 'Addison-Wesley Professional');";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Records into Publisher was inserted Successfully!" << std::endl;

	//created linked table
	sqlQuery = "CREATE TABLE LinkTable(ID INT PRIMARY KEY NOT NULL, AUT_ID INT NOT NULL, BK_ID INT NOT NULL, FOREIGN KEY (AUT_ID) REFERENCES Autors(AUT_ID) FOREIGN KEY(BK_ID) REFERENCES Books(BK_ID))";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);

	if (exit != SQLITE_OK) {
		std::cout << "Error Create LinkTable Table" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Table LinkTable was created Successfully" << std::endl;

	sqlQuery = "INSERT INTO LinkTable VALUES(1, 1, 5); INSERT INTO LinkTable VALUES(2, 1, 1); INSERT INTO LinkTable VALUES(3, 2, 2); INSERT INTO LinkTable VALUES(4, 2, 3); INSERT INTO LinkTable VALUES(5, 3, 2); INSERT INTO LinkTable VALUES(6, 4, 4)";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Insert INTO LinkTable" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Records into LinkTable was inserted Successfully!" << std::endl;


	sqlQuery = "CREATE TABLE Books(BK_ID INT PRIMARY KEY NOT NULL, PB_ID INT NOT NULL, BK_NAME TEXT NOT NULL, BK_PAGES INT NUT NULL, BK_PRICE REAL, FOREIGN KEY(BK_ID) REFERENCES LinkTable(BK_ID), FOREIGN KEY(PB_ID) REFERENCES Publishers(PUB_ID))";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);

	if (exit != SQLITE_OK) {
		std::cout << "Error Create Books Table" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Table Books was created Successfully" << std::endl;

	sqlQuery = "INSERT INTO Books VALUES(1, 1, 'The Lost City of Z', 400, 10.10); INSERT INTO Books VALUES(2, 4, 'C++ Templates: The Complete Guide(2nd Edition)', 832, 63.98); INSERT INTO Books VALUES(3, 4,'The Standard Library: A Tutorial and Reference(2nd Edition)', 1136, 64.58); INSERT INTO Books VALUES(4, 3,'The Silent Patient', 336, 16.19); INSERT INTO Books VALUES(5, 2,'Killers of the Flower Moon', 400, 12.17)";

	exit = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &pMessaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Insert INTO Books" << std::endl;
		sqlite3_free(pMessaggeError);
		sqlite3_close(DB);
		return -1;
	}
	else
		std::cout << "Records into Books was inserted Successfully!" << std::endl;
#endif DB_CREATION
	sqlite3_close(DB);

	return 0;
}

