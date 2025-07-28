#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string &s, int l, int r, vector<vector<int>> &dp){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = f(s, l+1, r-1, dp);
        else{
            int left = 1 + f(s, l, r - 1, dp);
            int rght = 1 + f(s, l + 1, r, dp);

            return dp[l][r] =  min(left, rght);
        } 
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return f(s, 0, s.size() - 1, dp);
    }
};

int main() {

    return 0;
}