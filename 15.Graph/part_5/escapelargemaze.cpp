#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_map<int, unordered_set<int>> block;
        unordered_map<int, unordered_set<int>> visited;
        for(auto it : blocked){
            block[it[0]].insert(it[1]);
        }

        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<pair<int, int>> q;
        q.push({source[0], source[1]});

        while(q.size()){
            auto [r, c] = q.front(); q.pop();

            if(r == target[0] and c == target[1]) return true;

            for(auto it : direction){
                int nr = r + it.first, nc = c + it.second;

                if(nr < 0 or nc < 0 or nr >= 1e6 or nc >= 1e6) continue;
                if(block.count(nr) and block[nr].count(nc)) continue;
                if(visited.count(nr) and visited[nr].count(nc)) continue;

                q.push({nr, nc});
                visited[nr].insert(nc);
            }
        }
        return false;
    }
};

int main() {

    return 0;
}