#include "Comment.h"
Comment::Comment()
{
}

Comment::Comment(User author, const std::string& text, uint16_t likes,uint16_t dislikes) :
	m_author(author), m_text(text), m_likes(likes),m_dislikes(dislikes)
{
}

const User& Comment::GetAuthor() const
{
	return m_author;
}

const std::string& Comment::GetText() const
{
	return m_text;
}

uint16_t Comment::GetLikes() const
{
	return m_likes;
}

uint16_t Comment::GetDislikes() const
{
	return m_dislikes;
}

void Comment::SetAuthor(User author)
{
	m_author = author;
}

void Comment::SetText(std::string text)
{
	m_text = text;
}

void Comment::SetLikes(uint16_t likes)
{
	m_likes = likes;
}

void Comment::SetDislikes(uint16_t dislikes)
{
	m_dislikes = dislikes;
}

Comment::~Comment()
{
}
