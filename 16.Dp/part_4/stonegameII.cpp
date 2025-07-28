#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101][2]; 

    int f(vector<int> &piles, int ind, bool aliceChance, int M) {
        if (ind >= piles.size()) return 0;

        if (dp[ind][M][aliceChance] != -1) return dp[ind][M][aliceChance];

        int result = aliceChance ? 0 : INT_MAX;
        int sum = 0;

        for (int x = 1; x <= 2 * M && ind + x <= piles.size(); x++) {
            sum += piles[ind + x - 1];
            if (aliceChance) {
                result = max(result, sum + f(piles, ind + x, false, max(M, x)));
            } else {
                result = min(result, f(piles, ind + x, true, max(M, x)));
            }
        }

        return dp[ind][M][aliceChance] = result;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return f(piles, 0, true, 1);
    }
};


int main() {

    return 0;
}