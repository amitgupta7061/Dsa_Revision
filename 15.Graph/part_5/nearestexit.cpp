#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr = tuple<int, int, int>;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        priority_queue<pairr, vector<pairr>, greater<>> pq;

        int m = maze.size(), n = maze[0].size();
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i = 0; i < n; i++){   // 1st row and last row
            if(maze[0][i] == '.' and (entrance[0] != 0 or entrance[1] != i)) pq.push({0, 0, i});
            if(maze[m-1][i] == '.' and (entrance[0] != m-1 or entrance[1] != i)) pq.push({0, m-1, i});
        }

        for(int i = 1; i < m - 1; i++){   // 1st col and last col
            if(maze[i][0] == '.' and (entrance[0] != i or entrance[1] != 0)) pq.push({0, i, 0});
            if(maze[i][n-1] == '.' and (entrance[0] != i or entrance[1] != n-1)) pq.push({0, i, n-1});
        }

        while(pq.size()){
            auto [step, r, c] = pq.top(); pq.pop();
            if(r == entrance[0] and c == entrance[1]) return step;

            for(auto it : direction){
                int nr = r + it.first, nc = c + it.second;
                if(nr >= 0 and nc >= 0 and nr < m and nc < n and maze[nr][nc] == '.'){
                    maze[nr][nc] = '+'; // mark as visited 
                    pq.push({step+1, nr, nc});
                }
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}