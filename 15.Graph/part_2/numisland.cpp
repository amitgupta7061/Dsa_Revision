#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(vector<vector<int>> &grid, int r, int c){
        return r >= 0 and c >= 0 and r < grid.size() and c < grid[0].size()
                and grid[r][c] == 1;
    }
    const vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void DFS(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited){
        visited[r][c] = true;
        for(auto it : direction){
            int nr = r + it.first, nc = c + it.second;
            if(isvalid(grid, nr, nc) and !visited[nr][nc]){
                DFS(grid, nr, nc, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    cnt++;
                    DFS(grid, i, j, visited);
                }
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}