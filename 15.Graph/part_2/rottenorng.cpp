#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int notrotten = 0, time = 0, m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.emplace(i, j);
                else if(grid[i][j] == 1) notrotten++;
            }
        }

        if (notrotten == 0) return 0;

        while(!q.empty()) {
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++) {
                auto [row, col] = q.front(); q.pop();
                for(auto [dx, dy] : direction) {
                    int nrow = row + dx, ncol = col + dy;
                    if(nrow < 0 || ncol < 0 || nrow >= m || ncol >= n || grid[nrow][ncol] != 1) continue;
                    q.emplace(nrow, ncol);
                    grid[nrow][ncol] = 2;
                    notrotten--;
                }
            }

            time++;
        }

        return notrotten == 0 ? time-1 : -1;
    }
};

int main(){
    
}