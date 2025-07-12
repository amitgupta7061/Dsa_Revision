#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}, 
                                             {1,1},{1,-1}, {-1,-1}, {-1,1}};

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                int liveCnt = 0;
                for(auto &it : directions){
                    int nr = r + it.first, nc = c + it.second;
                    if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;

                    if(board[nr][nc] == 1 || board[nr][nc] == 3) liveCnt++;
                }

                if(board[r][c] == 1){
                    if(liveCnt < 2 || liveCnt > 3) board[r][c] = 3;  // live to dead
                } else {
                    if(liveCnt == 3) board[r][c] = 2;  // dead to live
                }
            }
        }

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == 2) board[r][c] = 1;
                else if(board[r][c] == 3) board[r][c] = 0;
            }
        }
    }
};

int main() {

    return 0;
}