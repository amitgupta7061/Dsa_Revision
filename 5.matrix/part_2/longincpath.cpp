#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int f(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp){
        int ans = 0;
        if(dp[r][c] != -1) return dp[r][c];
        for(auto it : direction){
            int nr = r + it.first, nc = c + it.second;
            if(nr < 0 or nc < 0 or nr >= matrix.size() or nc >= matrix[0].size() 
            or matrix[nr][nc] <= matrix[r][c]) continue;

            ans =  max(ans, 1 + f(matrix, nr, nc, dp));
        }
        return dp[r][c] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxi = -1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                maxi = max(maxi, f(matrix, r, c, dp));
            }
        }

        return maxi + 1;
    }
};

int main() {

    return 0;
}