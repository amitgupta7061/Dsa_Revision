#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101][101];

    int f(int ind, int used, int curr, int n, int minProfit, vector<int>& group, vector<int>& profit) {

        if (ind == group.size()) return curr >= minProfit ? 1 : 0;
        if (dp[ind][used][curr] != -1) return dp[ind][used][curr];

        int ways = f(ind + 1, used, curr, n, minProfit, group, profit);

        if (used + group[ind] <= n) {
            int new_profit = min(minProfit, curr + profit[ind]);
            ways += f(ind + 1, used + group[ind], new_profit, n, minProfit, group, profit);
            ways %= mod;
        }

        return dp[ind][used][curr] = ways;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, n, minProfit, group, profit);
    }
};


int main() {

    return 0;
}