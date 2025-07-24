#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOk(int row, int col, int m){
        return row >= 0 and col >= 0 and row < m and col < m;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), result = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++) dp[n-1][i] = matrix[n-1][i];  // last row
        for(int r = n-2; r >= 0; r--){
            for(int c = n-1; c >= 0; c--){
                int l = (isOk(r+1, c-1, n)) ? dp[r+1][c-1] : INT_MAX;
                int b = (isOk(r+1, c, n))? dp[r+1][c] : INT_MAX;
                int w = (isOk(r+1, c+1, n)) ? dp[r+1][c+1] : INT_MAX;
                dp[r][c] =  matrix[r][c] + min({l, b, w});
            }
        }
        for(int i = 0; i < n; i++) result = min(result, dp[0][i]);
        return result;
    }
};

int main() {

    return 0;
}