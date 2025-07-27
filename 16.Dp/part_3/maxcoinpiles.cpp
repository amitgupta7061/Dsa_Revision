#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][2001];
    int f(vector<vector<int>> &piles, int ind, int k){
        if (k == 0 or ind >= piles.size()) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = f(piles, ind + 1, k);
        int take = 0, sum = 0;
        for (int j = 0; j < piles[ind].size() && j < k; j++) {
            sum += piles[ind][j];
            take = max(take, sum + f(piles, ind + 1, k - j - 1));
        }

        return dp[ind][k] = max(take, nottake);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));
        return f(piles, 0, k);
    }
};

int main() {

    return 0;
}