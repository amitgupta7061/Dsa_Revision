#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        pq.push({0, {0, 0}});
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while (!pq.empty()) {
            auto [effort, coord] = pq.top(); pq.pop();
            int r = coord.first, c = coord.second;

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == m - 1 && c == n - 1) return effort;

            for (auto [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc]) {
                    int newEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
        return -1;
    }
};



int main() {

    return 0;
}