#pragma once
class Database
{
public:
	void setDatabasePath(char*& dir);
	static int createDB(const char*);
	static int callback(void*, int, char**, char**);
	static int createTable(const char*);
	static int insertData(const char*);
	static int updateData(const char*);
	static int deleteData(const char*);
	static int selectData(const char*);
private:
	char* m_dir;
};
