#pragma once
#include "User.h"
#include <string>
#include "Comment.h"
#include <ctime>
#include <vector>

class Tweet
{
public:
	Tweet();
	Tweet(User author, const std::string& text, const time_t& publishDate,const int& noOfRetweets, const int& noOfLikes, const int& noOfDislikes, std::vector<Comment> comments);
	 User& GetAuthor();
	const std::string& GetText()const;
	const time_t GetPublishDate()const;
	const float GetPriority()const;
	const std::vector<Comment>& GetComments()const;
	const int& GetNoOfRetweets()const;
	const int& GetNoOfLikes()const;
	const int& GetNoOfDislikes()const;
	void SetAuthor(const User& author);
	void SetText(const std::string& text);
	void SetPublishDate();
	void SetNoOfRetweets(const int& noOfRetweets);
	void SetNoOfLikes(const int& noOfLikes);
	void SetNoOfDislikes(const int& noOfDislikes);
	void SetPriority(const float& priority);
	void SetComments(const std::vector <Comment>& comments);
	std::string timeStringFormat();
	~Tweet();

private:
	User m_author;
	std::string m_text;
	time_t m_publishDate;
	float m_priority;
	int m_noOfRetweets;
	int m_noOfLikes;
	int m_noOfDislikes;
	std::vector<Comment> m_comments;


};

