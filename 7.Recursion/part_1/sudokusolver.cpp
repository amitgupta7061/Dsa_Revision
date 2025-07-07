#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<vector<char>> &board, int r, int c, char num){
        // row check
        for(int i = 0; i < 9; i++)
            if(board[r][i] == num) return false;
        // col check
        for(int i = 0; i < 9; i++)
            if(board[i][c] == num) return false;
        //mat check
        int x = (r / 3) * 3, y = (c / 3) * 3;
        for(int i = x; i < x+3; i++)
            for(int j = y; j < y+3; j++)
                if(board[i][j] == num) return false;
        return true;
        
    }
    bool f(vector<vector<char>> &board, int r, int c){
        if(r > 9) return;
        if(c > 9) return f(board, r+1, 0);
        
        if(board[r][c] != '.') return f(board, r, c+1);

        for(char num = '1' ; num <= '9'; num++){
            if(canPlace(board, r, c, num)){
                board[r][c] = num;
                if(f(board, r, c + 1)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        f(board, 0, 0);
    }
};

int main() {

    return 0;
}