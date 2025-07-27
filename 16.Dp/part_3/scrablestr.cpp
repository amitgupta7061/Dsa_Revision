#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(const string &s1, const string &s2, unordered_map<string, bool> &dp) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        string key = s1 + "#" + s2;
        if (dp.count(key)) return dp[key];

        for (int i = 1; i < s1.size(); i++) {
            if (f(s1.substr(0, i), s2.substr(0, i), dp) &&
                f(s1.substr(i), s2.substr(i), dp))
                return dp[key] = true;

            if (f(s1.substr(0, i), s2.substr(s1.size() - i), dp) &&
                f(s1.substr(i), s2.substr(0, s1.size() - i), dp))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        return f(s1, s2, dp);
    }
};


int main() {

    return 0;
}