#include "Tweet.h"
Tweet::Tweet()
{

}

Tweet::Tweet(User author, const std::string& text, const time_t& publishDate, const int& noOfRetweets, const int& noOfLikes, const int& noOfDislikes, std::vector<Comment> comments) :
	m_author(author),
	m_text(text),
	m_publishDate(publishDate),
	m_noOfRetweets(noOfRetweets),
	m_noOfLikes(noOfLikes),
	m_noOfDislikes(noOfDislikes),
	m_comments(comments)
{
}

 User& Tweet::GetAuthor() 
{
	return m_author;
}

const std::string& Tweet::GetText() const
{
	return m_text;
}

const time_t Tweet::GetPublishDate() const
{
	return time_t();
}

const float Tweet::GetPriority() const
{
	return m_priority;
}


const std::vector<Comment>& Tweet::GetComments() const
{
	return m_comments;
}

const int& Tweet::GetNoOfRetweets() const
{
	return m_noOfRetweets;
}

const int& Tweet::GetNoOfLikes() const
{
	return m_noOfLikes;
}

const int& Tweet::GetNoOfDislikes() const
{
	return m_noOfDislikes;
}

void Tweet::SetAuthor(const User& author)
{
	m_author = author;
}

void Tweet::SetText(const std::string& text)
{
	m_text = text;
}

void Tweet::SetPublishDate()
{
	m_publishDate = time(0);
}

void Tweet::SetNoOfRetweets(const int& noOfRetweets)
{
	m_noOfRetweets = m_noOfRetweets;
}

void Tweet::SetNoOfLikes(const int& noOfLikes)
{
	m_noOfLikes = m_noOfLikes;
}

void Tweet::SetNoOfDislikes(const int& noOfDislikes)
{
	m_noOfDislikes = noOfDislikes;
}

void Tweet::SetPriority(const float& priority)
{
	m_priority = priority;
}


void Tweet::SetComments(const std::vector<Comment>& comments)
{
	m_comments = comments;
}
std::string Tweet::timeStringFormat()
{
	return std::to_string(localtime(&m_publishDate) ->tm_mday) + "/" + std::to_string(1 + localtime(&m_publishDate)->tm_mon) + "/" + std::to_string(1900 + localtime(&m_publishDate)->tm_year) + " " + std::to_string(localtime(&m_publishDate)->tm_hour) + ":" + std::to_string(localtime(&m_publishDate)->tm_min)+":"+ std::to_string(localtime(&m_publishDate)->tm_sec);;
}

Tweet::~Tweet()
{
}
