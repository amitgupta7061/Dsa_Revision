#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(q.size()){
            
        }
    }
};

int main() {

    return 0;
}