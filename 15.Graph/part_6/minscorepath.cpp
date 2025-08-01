#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<pair<int, int>> adj[], int src, vector<bool> &visited){
        visited[src] = true;
        for(auto &[neigh, cost] : adj[src]){
            if(visited[neigh]) continue;
            f(adj, neigh, visited);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for(auto &it : roads){
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
            adj[it[1] - 1].push_back({it[0] - 1, it[2]});
        }
        vector<bool> visited(n, false);
        f(adj, 0, visited);

        int mini = INT_MAX;
        for (auto& r : roads) {
            int u = r[0] - 1, v = r[1] - 1, cost = r[2];
            if (visited[u] && visited[v]) {
                mini = min(mini, cost);
            }
        }

        return mini;
    }
};

int main() {

    return 0;
}