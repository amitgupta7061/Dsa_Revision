#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &satisfaction, int ind, int time, vector<vector<int>> &dp){
        if(ind >= satisfaction.size()) return 0;
        if(dp[ind][time] != -1) return dp[ind][time];

        int notmake = f(satisfaction, ind + 1, time, dp);
        int make = time * satisfaction[ind] + f(satisfaction, ind + 1, time + 1, dp);

        return dp[ind][time] = max(make, notmake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(satisfaction, 0, 1, dp);
    }
};

int main() {

    return 0;
}