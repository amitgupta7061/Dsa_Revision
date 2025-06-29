#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(string &s, int ind, int cnt, vector<vector<int>> &dp){
        if (cnt < 0) return false; 
        if(ind >= s.length()){
            return cnt == 0;
        }
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        if(s[ind] == '(') return dp[ind][cnt] = f(s, ind+1, cnt+1, dp);
        else if(s[ind] == ')') return dp[ind][cnt] = f(s, ind+1, cnt-1, dp);
        else return dp[ind][cnt] = f(s, ind+1, cnt+1, dp) or f(s, ind+1, cnt-1, dp)
                                                          or f(s, ind+1, cnt, dp);
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return f(s, 0, 0, dp);
    }
};


int main() {

    return 0;
}