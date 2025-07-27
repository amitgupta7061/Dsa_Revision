#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string &s, int ind, int isOne, vector<vector<int>> &dp) {
        if (ind == s.size()) return 0;
        if (dp[ind][isOne] != -1) return dp[ind][isOne];

        int res = INT_MAX;
        if (isOne == 0) {
            int cont_withZero = f(s, ind + 1, 0, dp) + (s[ind] == '1' ? 1 : 0);
            int make_itone = f(s, ind + 1, 1, dp) + (s[ind] == '0' ? 1 : 0);
            res = min(cont_withZero, make_itone);
        } else {
            res = f(s, ind + 1, 1, dp) + (s[ind] == '0' ? 1 : 0);
        }

        return dp[ind][isOne] = res;
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(s, 0, 0, dp);
    }
};


int main() {

    return 0;
}