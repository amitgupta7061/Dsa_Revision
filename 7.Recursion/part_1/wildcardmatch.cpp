#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(string &s, string &p, int l, int r, unordered_map<string, bool> &dp){
        if(l == s.size() and r == p.size()) return true;
        if(r == p.size()) return false;
        string key = to_string(l) + "," + to_string(r);
        if(dp.count(key)) return dp[key];

        if(p[r] == '*'){
            if(l < s.size() && f(s, p, l+1, r, dp)) return dp[key] = true;
            return dp[key] = f(s, p, l, r+1, dp);
        }

        else if(s[l] == p[r] or p[r] == '?')
            return dp[key] = f(s, p, l+1, r+1, dp);

        else return dp[key] = false;
    }

    bool isMatch(string s, string p) {
        unordered_map<string, bool> dp;
        return f(s, p, 0, 0, dp);
    }
};


int main() {

    return 0;
}