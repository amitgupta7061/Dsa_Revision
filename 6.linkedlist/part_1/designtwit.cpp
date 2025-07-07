#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    unordered_map<int, vector<int>> post;
    unordered_map<int, set<int>> follow;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result = post[userId];
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        follow[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow[followeeId].erase(followerId);
    }
};

int main() {

    return 0;
}