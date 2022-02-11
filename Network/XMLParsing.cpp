#include "XMLParsing.h"


void XMLParsing::setField(const bool& credentials)
{
	fields_exist= credentials;
}
void XMLParsing::setUsername(const std::string& username)
{
	m_username = username;
}
void XMLParsing::setPassword(const std::string& password)
{
	m_password = password;
}
void XMLParsing::setFirstName(const std::string& firstName)
{
	m_firstName = firstName;
}
void XMLParsing::setLastName(const std::string& lastName)
{
	m_lastName = lastName;
}
void XMLParsing::setText(const std::string& text)
{
	m_text = text;
}
void XMLParsing::setAction(const std::string& action)
{
	m_action = action;
}
void XMLParsing::setNoLikes(int no_likes)
{
	m_no_likes = no_likes;
}
void XMLParsing::setNoComments(int no_comments)
{
	m_no_comments = no_comments;
}
void XMLParsing::setNoDislikes(int no_dislikes)
{
	m_no_dislikes = no_dislikes;
}
void XMLParsing::setPublishDate(const std::string& publishDate)
{
	m_publishDate = publishDate;
}
bool XMLParsing::getField()
{
	return fields_exist;
}
std::string XMLParsing::getUsername()
{
	return m_username;
}
std::string XMLParsing::getText()
{
	return m_text;
}
std::string XMLParsing::getAction()
{
	return m_action;
}
std::string XMLParsing::getFirstName()
{
	return m_firstName;
}
std::string XMLParsing::getLastName()
{
	return m_lastName;
}
std::string XMLParsing::getPassword()
{
	return m_password;
}
std::string XMLParsing::getPublishDate()
{
	return m_publishDate;
}
int XMLParsing::getNoDislikes()
{
	return m_no_dislikes;
}
int XMLParsing::getNoLikes()
{
	return m_no_likes;
}
int XMLParsing::getNoComments()
{
	return m_no_comments;
}
void XMLParsing::load(const std::string& filename)
{
	ptree tree;
	read_xml(filename, tree);
	BOOST_FOREACH(ptree::value_type & v, tree.get_child("file.User")) {
		if (v.first == "infoUser")
		{
			m_username = v.second.get<std::string>("<xmlattr>.Username");
			m_password = v.second.get<std::string>("<xmlattr>.Password");
			m_firstName = v.second.get<std::string>("<xmlattr>.FirstName");
			m_lastName = v.second.get<std::string>("<xmlattr>.LastName");
			fields_exist = v.second.get<bool>("<xmlattr>.fieldsExist");
		}
		else if (v.first == "tweet")
		{
			m_text = v.second.get<std::string>("<xmlattr>.text");
			m_no_likes = v.second.get<int>("<xmlattr>.No_likes");
			m_publishDate = v.second.get<std::string>("<xmlattr>.PublishDate");
			m_no_dislikes = v.second.get<int>("<xmlattr>.No_dislikes");
			m_no_retweets = v.second.get<int>("<xmlattr>.No_retweets");
			m_no_comments= v.second.get<int>("<xmlattr>.No_comments");
		}
		else if(v.first == "Action")
		{
			m_action = v.second.get<std::string>("<xmlattr>.Type");
		}
	}
}
void XMLParsing::save(const std::string& filename)
{
	ptree tree;
	tree.add("file.User.infoUser.<xmlattr>.Username", m_username);
	tree.add("file.User.infoUser.<xmlattr>.Password", m_password);
	tree.add("file.User.infoUser.<xmlattr>.fieldsExist", fields_exist);
	tree.add("file.User.infoUser.<xmlattr>.FirstName", m_firstName);
	tree.add("file.User.infoUser.<xmlattr>.LastName", m_lastName);
	tree.add("file.User.Action.<xmlattr>.Type", m_action);

	tree.add("file.User.tweet.<xmlattr>.PublishDate",m_publishDate);
	tree.add("file.User.tweet.<xmlattr>.text", m_text);
	tree.add("file.User.tweet.<xmlattr>.No_likes", m_no_likes);
	tree.add("file.User.tweet.<xmlattr>.No_dislikes", m_no_dislikes);
	tree.add("file.User.tweet.<xmlattr>.No_retweets", m_no_retweets);
	tree.add("file.User.tweet.<xmlattr>.No_comments", m_no_comments);
	write_xml(filename, tree);
}

