#include "SearchBar.h"

User SearchBar::searchForUsers(const std::string& userName)const
{
    ///select username from User where username=userName voi returna acest user din baza de date
    return User();
}

Tweet SearchBar::searchForTweets(const std::string& text)const
{
    ///select * from Tweet where text=text voi returna tweetul din baza de date
    return Tweet();
}

int SearchBar::levDistance(const std::string& str1, const std::string& str2) const
{
    int len1 = str1.length();
    int len2 = str2.length();


    std::vector<std::vector<int>>DP;
    DP.resize(2);
    for (int i = 0; i < 2; i++)
        DP[i].resize(len1 + 1);
    for (int i = 0; i <= len1; i++)
        DP[0][i] = i;

    for (int i = 1; i <= len2; i++) {

        for (int j = 0; j <= len1; j++) {

            if (j == 0)
                DP[i % 2][j] = i;


            else if (str1[j - 1] == str2[i - 1]) {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }


            else {
                DP[i % 2][j] = 1 + std::min(DP[(i - 1) % 2][j],
                    std::min(DP[i % 2][j - 1],
                        DP[(i - 1) % 2][j - 1]));
            }
        }
    }

    return DP[len2 % 2][len1];
}

void SearchBar::addWordToDictionary(std::string word)
{
	if (dictionary.find(word) == dictionary.end())
	{
		std::vector<int>idPost;
		//caut cuvantul in fiecare text din fiecare postare
		//legatura cu baza de date
		dictionary.insert({ word,idPost });
	}
}

std::vector<int> SearchBar::searchTweets(std::string word)
{
	std::vector<int>idPost;
	if (dictionary.find(word) == dictionary.end())
	{
		return idPost;
		//nu exista 
	}
	else {
		idPost = dictionary[word];
		return idPost;
	}
}
