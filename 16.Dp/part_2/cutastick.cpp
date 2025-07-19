#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int totalLength, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(totalLength);
        sort(cuts.begin(), cuts.end());

        int numOfCuts = cuts.size();
        int costMatrix[110][110] = {0}; 

        for (int len = 2; len < numOfCuts; ++len) {
            for (int i = 0; i + len < numOfCuts; ++i) {
                int j = i + len;
                costMatrix[i][j] = 1 << 30;
              
                for (int k = i + 1; k < j; ++k) {
                    int cost = costMatrix[i][k] + costMatrix[k][j] + cuts[j] - cuts[i];
                    costMatrix[i][j] = min(costMatrix[i][j], cost);
                }
            }
        }

        return costMatrix[0][numOfCuts - 1];
    }
};

class Solution {
public:
    int f(vector<int>& cuts, int l, int r, vector<vector<int>> &dp) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int minCost = INT_MAX;
        for (int i = l; i <= r; i++) {
            int cost = cuts[r + 1] - cuts[i - 1] + f(cuts, i, i - 1, dp) + f(cuts, i + 1, r, dp);
            minCost = min(minCost, cost);
        }

        return dp[l][r] = minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(cuts, 1, cuts.size() - 2, dp);
    }
};


int main() {

    return 0;
}