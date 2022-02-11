#pragma once
#include <vector>
#include<algorithm>
#include "User.h"
#include "Tweet.h"
#include <string>
#include<map>
class SearchBar
{
public:
	User searchForUsers(const std::string&)const;
	Tweet searchForTweets(const std::string&)const;
	int levDistance(const std::string& str1, const std::string& str2)const;
	void addWordToDictionary(std::string word);
	std::vector<int> searchTweets(std::string word);//le returnezi id-ul

private:
	std::map<std::string, std::vector<int>>dictionary;

};
