#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>> &grid, int r, int c, int m, int n, vector<vector<int>> dp){
        if(r == m - 1 and c == n - 1) return 1;
        if(r >= m or c >= n or grid[r][c] == 1) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = f(grid, r+1, c, m, n, dp) + f(grid, r, c+1, m, n, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1 or grid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(grid, 0, 0, m, n, dp);
    }
};

int main() {

    return 0;
}