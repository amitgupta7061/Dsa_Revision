#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>> &dungeon, int r, int c, vector<vector<int>> &dp){
        if(r >= dungeon.size() or c >= dungeon[0].size()) return INT_MAX;
        if(r == dungeon.size() -1 and c == dungeon[0].size() - 1){
            return max(1, 1 - dungeon[r][c]);
        }
        if(dp[r][c] != -1) return dp[r][c];

        int nextHealth = min(f(dungeon, r+1, c, dp), f(dungeon, r, c+1, dp));
        return dp[r][c] = max(1, nextHealth - dungeon[r][c]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(dungeon, 0, 0, dp);
    }
};  

int main() {

    return 0;
}