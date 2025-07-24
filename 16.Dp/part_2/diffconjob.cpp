#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &jobDifficulty, int ind, int day, int &d, vector<vector<int>> &dp){
        if(day > d or ind > jobDifficulty.size()) return 1e6;
        if(day == d){
            if(ind == jobDifficulty.size()) return 0;
            else return 1e6;
        }
        if(dp[ind][day] != -1) return dp[ind][day];
        int mini = 1e6, maxDay = 0;
        for(int i = ind; i < jobDifficulty.size(); i++){
            maxDay = max(maxDay, jobDifficulty[i]);
            mini = min(mini, maxDay + f(jobDifficulty, i+1, day+1, d, dp));
        }
        return dp[ind][day] = mini;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(jobDifficulty.size()+1, vector<int>(d+1, -1));
        int result = f(jobDifficulty, 0, 0, d, dp);
        return result == 1e6 ? -1 : result;
    }
};

int main() {

    return 0;
}