#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<char>> &mat, int r, int c, int &maxi, vector<vector<int>> &dp){
        if(r == mat.size() or c == mat[0].size()) return 0;
        if(dp[r][c] != -1) return dp[r][c];

        int rght = f(mat, r, c+1, maxi, dp);
        int btm  = f(mat, r+1, c, maxi, dp);
        int diag = f(mat, r+1, c+1, maxi, dp);

        if(mat[r][c] == '1'){
            int result = 1 + min({rght, btm, diag});
            maxi = max(maxi, result);
            return dp[r][c] = result;
        } else return dp[r][c] = 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        f(matrix, 0, 0, maxi, dp);
        return maxi * maxi;
    }
};

int main() {

    return 0;
}