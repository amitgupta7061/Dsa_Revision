#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (string& s : strs) {
            int zeros = count(s.begin(), s.end(), '0'), ones = s.length() - zeros;

            for (int i = m; i >= zeros; i--){
                for (int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

class Solution {
public:
    int dp[601][101][101];
    int f(vector<string>& strs, int ind, int m, int n) {
        if (ind == strs.size()) return 0;
        if (dp[ind][m][n] != -1) return dp[ind][m][n];

        int zeros = count(strs[ind].begin(), strs[ind].end(), '0'), ones = strs[ind].length() - zeros;

        int notTake = f(strs, ind + 1, m, n);
        int take = 0;
        if (m >= zeros && n >= ones) {
            take = 1 + f(strs, ind + 1, m - zeros, n - ones);
        }

        return dp[ind][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return f(strs, 0, m, n);
    }
};


int main() {

    return 0;
}