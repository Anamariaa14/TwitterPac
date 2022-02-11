#pragma once
#include<string>
#include<vector>
#include<algorithm>
class User
{
public:
	User();
	User(std::string username, std::string password, std::string firstName, std::string secondName);
	const std::string& GetUsername() const;
	const std::string& GetPassword() const;
	const std::string& GetFirstName() const;
	const std::string& GetSecondName() const;
	void SetUsername(std::string username);
	void SetPassword(std::string password);
	void SetFirstName(std::string firstName);
	void SetSecondName(std::string secondName);
	friend bool operator ==(const User &u1,const User&u2);
	~User();

private:
	std::string m_username;
	std::string m_password;
	std::string m_firstName;
	std::string m_secondName;
};

