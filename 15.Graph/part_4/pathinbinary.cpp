#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0},{0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] or grid[n-1][n-1]) return -1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        pq.push({1, {0, 0}});
        vector<vector<bool>> visited(n, vector<bool>(n ,false));
        visited[0][0] = true;

        while(pq.size()){
            auto [dist, coord] = pq.top(); pq.pop();
            auto [r, c] = coord;
            if(r == n-1 and c == n-1) return dist;

            for(auto it : dir){
                int nr = r + it.first, nc = c + it.second;
                if(nr >= 0 and nc >= 0 and nr < n and nc < n and grid[nr][nc] == 0 and !visited[nr][nc]){
                    visited[nr][nc] = true;
                    pq.push({dist + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}