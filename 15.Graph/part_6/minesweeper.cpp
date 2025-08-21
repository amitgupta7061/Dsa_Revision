#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size(), r = click[0], c = click[1];
        
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1},{1,1}, {1,-1}, {-1,1}, {-1,-1}};
        
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 or c < 0 or r >= m or c >= n or board[r][c] != 'E') return;
            
            int mines = 0;
            for (auto it : dirs) {
                int nr = r + it.first, nc = c + it.second;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'M') mines++;
            }
            
            if (mines > 0) {
                board[r][c] = '0' + mines; 
                return;
            }
            
            board[r][c] = 'B';
            for (auto [dr, dc] : dirs) dfs(r + dr, c + dc);
        };
        
        dfs(r, c);
        return board;
    }
};


int main() {

    return 0;
}