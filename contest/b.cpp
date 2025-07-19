#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};

    long long f(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] <= 0) return 0;
        
        long long res = grid[r][c];
        grid[r][c] = -1;

        for (auto it : direction) {
            int nr = r + it.first, nc = c + it.second;
            res += f(grid, nr, nc);
        }

        return res;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = f(grid, i, j);
                    if (sum % k == 0) cnt++;
                }
            }
        }

        return cnt;
    }
};
