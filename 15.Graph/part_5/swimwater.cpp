#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr = tuple<int, int, int>;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pairr, vector<pairr>, greater<>> pq;
        pq.emplace(0, 0, 0);
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(pq.size()){
            auto [time, r, c] = pq.top(); pq.pop();
            if(visited[r][c]) continue;
            visited[r][c] = true;

            if(r == n-1 and c == n-1) return time;
        
            for(auto it : dir){
                int nr = r + it.first, nc = c + it.second;
                if(nr >= 0 and nc >= 0 and nr < n and nc < n and !visited[nr][nc]){
                    int newTime = max(time, grid[nr][nc]);
                    pq.emplace(newTime, nr, nc);
                }
            }
        }

        return -1;
    }
};

int main() {

    return 0;
}