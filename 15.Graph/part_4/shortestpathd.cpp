#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> result(adj.size(), -1), visited(adj.size(), 0);
        result[src] = 0; visited[src] = true;
        queue<pair<int, int>> q;
        q.push({src, 0});

        while(q.size()){
            auto [curr, dist] = q.front(); q.pop();
            for(auto neigh : adj[curr]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    result[neigh] = dist + 1;
                    q.push({neigh, result[neigh]});
                }
            }
        }
        return result;
    }
};

int main() {

    return 0;
}