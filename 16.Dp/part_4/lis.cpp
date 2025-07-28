#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp(obstacles.size(), 1);

        for(int i = 1; i < obstacles.size(); i++){
            for(int j = 0; j < i; j++){
                if(obstacles[j] <= obstacles[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp;
    }
}; 

int main() {

    return 0;
}