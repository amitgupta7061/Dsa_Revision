#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<int> adj[], int src, vector<bool> &visited, vector<bool> &ancestor){
        visited[src]  = true;
        ancestor[src] = true;   
        for(auto neigh : adj[src]){
            if(!visited[neigh]){
                if(DFS(adj, neigh, visited, ancestor)) return true;
            } else if(ancestor[neigh]){
                return true;
            }
        }
        ancestor[src] = false;
        return false;
    }
    bool isCyclic(int vertex, vector<vector<int>> &edges) {
        vector<int> adj[vertex];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> visited(vertex, false), ancestor(vertex, false);

        for(int i = 0; i < vertex; i++){
            if(DFS(adj, i, visited, ancestor)) return true;
        }

        return false;
    }
};

class Solution{
public:
    bool isCyclic(int vertex, vector<vector<int>> &edges) {
        vector<int> adj[vertex];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>Indegree(vertex, 0);

        for(int i = 0; i < vertex; i++) {
            for(auto it : adj[i]) Indegree[it]++;
        }
        queue<int> q;
        for(int i = 0; i < vertex; i++) {
            if(Indegree[i] == 0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;
            for(auto neigh : adj[node]) {
                  Indegree[neigh]--;
                  if(Indegree[neigh] == 0) q.push(neigh);
            }
        }

        return cnt != vertex;
    }
};

int main() {

    return 0;
}