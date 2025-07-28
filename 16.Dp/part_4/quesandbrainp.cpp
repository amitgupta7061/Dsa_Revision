#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(vector<vector<int>> &questions, long long ind, vector<long long> &dp){
        if(ind >= questions.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(questions[ind][0] + f(questions, ind+questions[ind][1]+1, dp), f(questions, ind+1, dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1, -1);
        return f(questions, 0, dp);
    }
};

int main() {

    return 0;
}