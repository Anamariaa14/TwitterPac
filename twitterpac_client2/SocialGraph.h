#pragma once
#include<iostream>
#include"User.h"
#include<vector>
#include<unordered_map>
class SocialGraph
{
public:
	SocialGraph();
	SocialGraph(std::vector<User> users, std::unordered_map<std::string, std::vector<User>>friends);
	std::vector<User> GetUsers()const;
	void AddUser(const User& u);
	void AddFriend(const User& u1, const User& u2);
	std::vector<User> GetUserFriends(const User& u)const;
	std::vector<User> GetFollowSuggestions(const User& u);
	std::vector<int> minDistance(const User& u);

private:
	std::vector<User> m_users; //noduri de useri ?*pointer la user
	//std::vector<std::vector<User>>m_friends; //lista de adiacenta pentru prietenii
	std::unordered_map<std::string, std::vector<User>>m_friends; //? 

};


