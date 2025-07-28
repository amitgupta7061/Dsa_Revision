#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int f(string &s, int ind, int k, vector<int> &dp) {
        if (ind == s.size()) return 1;
        if (s[ind] == '0') return 0;
        if (dp[ind] != -1) return dp[ind];

        long long num = 0;
        int ways = 0;
        for (int i = ind; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num > k) break;
            ways = (ways + f(s, i + 1, k, dp)) % MOD;
        }
        return dp[ind] = ways;
    }

    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return f(s, 0, k, dp);
    }
};


int main() {

    return 0;
}