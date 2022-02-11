#pragma once
#include "Database.h"
#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
#include <vector>
#include "../Network/XMLParsing.h"
//#include "XMLParsing.h"
void Database::setDatabasePath(char*& dir)
{
	m_dir = dir;
}

int Database::createDB(const char* s)
{
	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

int Database::callback(void* NotUsed, int argc, char** argv, char** azColName)
{

	std::cout << "In callback\n";
	std::string users; 
	for (int i = 0; i < argc; i++) {
		// column name and value
		std::cout << azColName[i] << ": " << argv[i] << "\n";
		XMLParsing document;
		document.load("../date.xml");
		if (document.getAction() == "UserSearch")
		{
			std::string aux (argv[i]);
			users =users+ aux;
			users =users+ " ";
			std::cout << aux << " aux\n";
			document.setUsername(users);
		}
		if (azColName[i] == "FNAME")
			document.setFirstName(argv[i]);
		if (azColName[i] == "LNAME")
			document.setLastName(argv[i]);
		document.setField(true);
		document.save("../date.xml");
	}
	std::cout << "\n";
	return 0;
}

int Database::createTable(const char* s)
{
	sqlite3* DB;
	char* messageError;
	std::vector<std::string> tabeleSQL;


	std::string sql = "CREATE TABLE IF NOT EXISTS USER("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"USERNAME	  CHAR(30) UNIQUE, "
		"PASSWORD     CHAR(30), "
		"FNAME		  TEXT NOT NULL, "
		"LNAME   TEXT NOT NULL, "
		"NO_OF_TWEETS INT NOT NULL,"
		"NO_OF_FOLLOWERS INT NOT NULL,"
		"NO_OF_FOLLOWING INT NOT NULL);";

	tabeleSQL.push_back(sql);

	sql = "CREATE TABLE IF NOT EXISTS TWEET("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"RETWEET_ID INTEGER DEFAULT -1, "
		"USERNAME	  CHAR(30), "
		"DATE CHAR(30) NOT NULL, "
		"TEXT CHAR(140) NOT NULL, "
		"NO_OF_LIKES    INT NOT NULL, "
		"NO_OF_DISLIKES   TEXT NOT NULL, "
		"NO_OF_RETWEETS INT NOT NULL,"
		"NO_OF_COMMENTS INT NOT NULL,"
		"FOREIGN KEY(RETWEET_ID) REFERENCES TWEET(ID) ON DELETE SET NULL ON UPDATE CASCADE );";

	tabeleSQL.push_back(sql);

	sql = "CREATE TABLE IF NOT EXISTS USER_FOLLOW("
		"USERNAME1 CHAR(30),"
		"USERNAME2 CHAR(30),"
		"FOREIGN KEY (USERNAME1) REFERENCES USER(USERNAME) ON DELETE CASCADE ON UPDATE CASCADE,"
		"FOREIGN KEY (USERNAME2) REFERENCES USER(USERNAME) ON DELETE CASCADE ON UPDATE CASCADE,"
		"PRIMARY KEY(USERNAME1, USERNAME2));";

	tabeleSQL.push_back(sql);

	sql = "CREATE TABLE IF NOT EXISTS COMMENT("
		"COMMENT_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"TWEET_ID INT NOT NULL, "
		"USER_ID INTEGER NOT NULL, "
		"COMMENT_DATE TEXT NOT NULL, "
		"TEXT CHAR(140) NOT NULL, "
		"NO_OF_LIKES INT NOT NULL, "
		"FOREIGN KEY(TWEET_ID) REFERENCES TWEET(ID) ON DELETE CASCADE ON UPDATE CASCADE, "
		"FOREIGN KEY(USER_ID) REFERENCES USER(ID) ON DELETE CASCADE ON UPDATE CASCADE); ";

	tabeleSQL.push_back(sql);

	for (const auto& tabel : tabeleSQL) {
		try
		{
			int exit = 0;
			exit = sqlite3_open(s, &DB);
			/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
			exit = sqlite3_exec(DB, tabel.c_str(), NULL, 0, &messageError);
			if (exit != SQLITE_OK) {
				std::cerr << "Error in createTable function.\n";
				sqlite3_free(messageError);
			}
			else
				std::cout << "Table created Successfully\n";
			sqlite3_close(DB);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	return 0;
}

int Database::insertData(const char* s)
{
	std::string sql;
	sqlite3* DB;
	char* messageError;
	XMLParsing document;
	document.load("../date.xml");
	if (document.getAction() == "Register")
	{
		sql = "INSERT INTO USER (USERNAME, PASSWORD, FNAME, LNAME, NO_OF_TWEETS,NO_OF_FOLLOWERS,NO_OF_FOLLOWING) VALUES('" + document.getUsername() + "','"
			+ document.getPassword() + "','" + document.getFirstName() + "','" + document.getLastName() + "','0','0','0')";

	}
	else if (document.getAction() == "Tweet")
	{
		sql = "INSERT INTO TWEET (USERNAME, DATE, TEXT, NO_OF_LIKES, NO_OF_DISLIKES, NO_OF_RETWEETS, NO_OF_COMMENTS) VALUES('" + document.getUsername() + "','"
			+ document.getPublishDate() + "','" + document.getText() + "','" + std::to_string(document.getNoLikes()) + "','" + std::to_string(document.getNoDislikes()) + "','0','" + std::to_string(document.getNoComments()) + "')";
		std::cout << sql << "\n";
	}
	
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error in insertData function.\n";
		sqlite3_free(messageError);
	}
	else
		std::cout << "Records inserted Successfully!\n";

	return 0;
}

int Database::updateData(const char* s)
{
	sqlite3* DB;
	char* messageError;

	std::string sql("UPDATE USER SET NO_OF_FOLLOWERS = 777 WHERE LNAME = 'Cooper'");

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error in updateData function.\n";
		sqlite3_free(messageError);
	}
	else
		std::cout << "Records updated Successfully!\n";

	return 0;
}

int Database::deleteData(const char* s)
{
	sqlite3* DB;
	char* messageError;
	std::string sql = "DELETE FROM USER;";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error in deleteData function.\n";
		sqlite3_free(messageError);
	}
	else
		std::cout << "Records deleted Successfully!\n";

	return 0;
}

int Database::selectData(const char* s)
{
	sqlite3* DB;
	std::string sql;
	char* messageError;
	XMLParsing document;
	document.load("../date.xml");
	std::cout << "SELECT DATA\n";
	if (document.getAction() == "Login")
	{
	sql = "SELECT * FROM USER";
	}
	else if (document.getAction() == "UserSearch")
	{
		sql = "SELECT USERNAME FROM USER ";
	}
	std::cout << sql << "\n";
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		std::cerr << "Error in selectData function.\n";
		sqlite3_free(messageError);
	}
	else
	{
		std::cout << "Records selected Successfully!\n";
	}
	return 0;
}
