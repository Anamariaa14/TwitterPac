#pragma once
#include <unordered_map>
#include "SearchBar.h"
#include "User.h"
#include "Tweet.h"
#include<queue>
#include"SocialGraph.h"
auto PublishDateComp = [](Tweet t1, Tweet t2) {return t1.GetPublishDate() > t2.GetPublishDate(); };
auto PriorityComp = [](Tweet t1, Tweet t2) {return t1.GetPriority() > t2.GetPriority(); };
class Dashboard
{
public:
	Dashboard();
	std::priority_queue < Tweet, std::vector<Tweet>, decltype(PriorityComp)> GetFeed()const;
	void SetFeed(std::vector<Tweet>, const User& u);
	void SetProfile(std::vector<Tweet>profile);
	void postTweet();
	void deleteTweet();

private:
	SocialGraph m_graph;
	SearchBar m_search;
	std::priority_queue<Tweet, std::vector<Tweet>, decltype(PublishDateComp)>m_profile;
	std::priority_queue<Tweet, std::vector<Tweet>, decltype(PriorityComp)>m_feed;
};

