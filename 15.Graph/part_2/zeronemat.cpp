#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<tuple<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.emplace(i, j);
                    result[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(q.size()){
            auto [row, col] = q.front(); q.pop();

            for(auto it : direction){
                int nrow = row + it.first, ncol = col + it.second;
                if(nrow < 0 or ncol < 0 or nrow >= m or ncol >= n or result[nrow][ncol] != -1) continue;

                result[nrow][ncol] = result[row][col] + 1;
                q.emplace(nrow, ncol);
            }
        }
        return result;
    }
};

int main() {

    return 0;
}