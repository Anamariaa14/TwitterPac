#include "Dashboard.h"

std::priority_queue<Tweet, std::vector<Tweet>, decltype(PriorityComp)> Dashboard::GetFeed() const
{
	return m_feed;
}

void Dashboard::SetFeed(std::vector<Tweet> tweets,const User& u)
{
	std::vector<int>dist;
	dist = m_graph.minDistance(u);
	for (auto tweet : tweets)
	{
		int pos = std::distance(m_graph.GetUsers().begin(), std::find(m_graph.GetUsers().begin(), m_graph.GetUsers().end(), tweet.GetAuthor()));
		float priority = 1 /dist[pos]  + 1 / (time(0) - tweet.GetPublishDate()) - 1 / tweet.GetNoOfLikes();
		tweet.SetPriority(priority);
		m_feed.push(tweet);
	}
}

void Dashboard::SetProfile(std::vector<Tweet> profile)
{

	for (auto tweet : profile)
	{
		m_feed.push(tweet);
	}
}

void Dashboard::postTweet()
{
}

void Dashboard::deleteTweet()
{
}
