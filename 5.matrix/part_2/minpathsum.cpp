#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>> &grid, int r, int c, int m, int n, vector<vector<int>> &dp){
        if(r == m - 1 and c == n - 1) return grid[r][c];
        if(r >= m or c >= n) return 1e6;
        if(dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = grid[r][c] + min(f(grid, r+1, c, m, n, dp), f(grid, r, c+1, m, n, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(grid, 0, 0, m, n, dp);
    }
};

int main() {

    return 0;
}