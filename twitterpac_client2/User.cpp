#include "User.h"
User::User()
{
}

User::User(std::string username, std::string password, std::string firstName, std::string secondName) :
	m_username(username),
	m_password(password),
	m_firstName(firstName),
	m_secondName(secondName)
{
}

const std::string& User::GetUsername() const
{
	return m_username;
}

const std::string& User::GetPassword() const
{
	return m_password;
}

const std::string& User::GetFirstName() const
{
	return m_firstName;
}

const std::string& User::GetSecondName() const
{
	return m_secondName;
}

void User::SetUsername(std::string username)
{
	m_username = username;
}

void User::SetPassword(std::string password)
{
	m_password = password;
}

void User::SetFirstName(std::string firstName)
{
	m_firstName = firstName;
}

void User::SetSecondName(std::string secondName)
{
	m_secondName = secondName;
}

bool operator==(const User& u1,const User &u2)
{
	return u1.m_username==u2.m_username;
}

User::~User()
{
}
