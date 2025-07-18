#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, int root, vector<vector<int>> &dp){
        if(n < 0 or root <= 0) return 1e6;
        if(n == 0) return 1;
        if(dp[n][root] != -1) return dp[n][root];

        return dp[n][root] = min(1 + f(n - root*root, root, dp), f(n, root-1, dp));
    }
    int numSquares(int n) {
        int root = (int)sqrt(n);
        vector<vector<int>> dp(n+1, vector<int>(root+1, -1));
        return f(n, root, dp) - 1;
    }
};

int main() {

    return 0;
}