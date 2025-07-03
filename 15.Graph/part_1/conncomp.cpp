#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> adj[], int node, unordered_set<int> &visited){
        visited.insert(node);
        for(auto neigh : adj[node]){
            if(!visited.count(neigh)) f(adj, neigh, visited);
        }
    }
    int findNumberOfComponent(int V, int E, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        unordered_set<int> visited;
        for(int i = 0; i < V; i++){
            if(!visited.count(i)){
                f(adj, i, visited); cnt++;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}