#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parent(m * n);
        for (int i = 0; i < parent.size(); i++) parent[i] = i;
      
        vector<vector<int>> grid(m, vector<int>(n));
        int count = 0;
        vector<int> result, directions = {-1, 0, 1, 0, -1};

        function<int(int)> Find = [&](int x){
            if (parent[x] != x) parent[x] = Find(parent[x]);
            return parent[x];
        };

        function<void(int, int)> Union = [&](int x, int y){
            int rootX = Find(x), rootY = Find(y);
            if (rootX != rootY) parent[rootY] = rootX;
        };
      
        for (auto& pos : positions) {
            int row = pos[0], col = pos[1];
          
            if (grid[row][col] == 1) {
                result.push_back(count); continue;
            }
          
            grid[row][col] = 1;
            count++;
          
            for (int k = 0; k < 4; ++k) {
                int x = row + directions[k], y = col + directions[k + 1];
                if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1) {
                    if (Find(x * n + y) != Find(row * n + col)) {
                        Union(x * n + y, row * n + col);
                        count--;
                    }
                }
            }
          
            result.push_back(count);
        }
      
        return result;
    }
};

int main() {

    return 0;
}