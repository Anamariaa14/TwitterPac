#pragma once
#include <boost/property_tree/ptree.hpp>
#include<boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <iostream>
using boost::property_tree::ptree;
class XMLParsing
{
private:
	std::string m_username, m_password,m_firstName, m_lastName,m_action,m_text,m_publishDate;
	int m_no_likes, m_no_dislikes, m_no_retweets, m_no_comments;
	bool fields_exist;
public:
	void setField(const bool&);
	void setUsername(const std::string&);
	void setPassword(const std::string&);
	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	void setText(const std::string&);
	void setAction(const std::string&);
	void setNoLikes(int);
	void setNoComments(int);
	void setNoDislikes(int);
	void setPublishDate(const std::string&);
	bool getField();
	std::string getUsername();
	std::string getText();
	std::string getAction();
	std::string getFirstName();
	std::string getLastName();
	std::string getPassword();
	std::string getPublishDate();
	int getNoDislikes();
	int getNoLikes();
	int getNoComments();
	void load(const std::string&);
	void save(const std::string&);
};
