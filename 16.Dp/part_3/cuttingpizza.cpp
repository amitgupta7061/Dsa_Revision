#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n, MOD = 1e9 + 7;
    int dp[11][51][51];
    bool hasApple(vector<string>& pizza, int r1, int c1, int r2, int c2) {
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }

    int f(vector<string>& pizza, int k, int r, int c) {
        if (k == 1) {
            return hasApple(pizza, r, c, m, n) ? 1 : 0;
        }
        if(dp[k][r][c] != -1) return dp[k][r][c];

        int ways = 0;
        for (int nr = r + 1; nr < m; nr++) {
            if (hasApple(pizza, r, c, nr, n)) {
                ways = (ways + f(pizza, k - 1, nr, c)) % MOD;
            }
        }
        for (int nc = c + 1; nc < n; nc++) {
            if (hasApple(pizza, r, c, m, nc)) {
                ways = (ways + f(pizza, k - 1, r, nc)) % MOD;
            }
        }

        return dp[k][r][c] = ways;
    }


    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        memset(dp, -1, sizeof(dp));
        return f(pizza, k, 0, 0);
    }
};


int main() {

    return 0;
}