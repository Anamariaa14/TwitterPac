#pragma once
#include"User.h"
#include<iostream>
#include<string>
#include<vector>
class Comment
{
public:
	Comment();
	Comment(User author, const std::string& text, uint16_t likes,uint16_t dislikes);
	const User& GetAuthor()const;
	const std::string& GetText()const;
	uint16_t GetLikes()const;
	uint16_t GetDislikes()const;
	void SetAuthor(User author);
	void SetText(std::string text);
	void SetLikes(uint16_t likes);
	void SetDislikes(uint16_t dislikes);
	~Comment();
private:
	User m_author;
	std::string m_text;
	uint16_t m_likes;
	uint16_t m_dislikes;
};

