#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<int> adj[], int src, int parent, vector<bool> &visited){
        visited[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]){
                if(DFS(adj, neigh, src, visited)) return true;
            } else if(parent != neigh){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int vertex, vector<vector<int>>& edges) {
        vector<int> adj[vertex];
        for(auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(vertex, false);
        for(int i = 0; i < vertex; i++){
            if(!visited[i]){
                if(DFS(adj, i, -1, visited)) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isCycle(int vertex, vector<vector<int>>& edges) {
        vector<int> adj[vertex];
        for(auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(vertex, false);
        for(int i = 0; i < vertex; i++){
            if(!visited[i]){
                queue<pair<int , int>> q;
                q.push({i, -1});
                visited[i] = true;

                while(q.size()){
                    auto it = q.front(); q.pop();
                    int curr = it.first, parent = it.second;

                    for(auto neigh : adj[curr]){
                        if(!visited[neigh]){
                            visited[neigh] = true;
                            q.push({neigh, curr});
                        } else if(neigh != parent){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {

    return 0;
}