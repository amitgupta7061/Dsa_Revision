#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> adj[], int node, vector<int> &result, unordered_set<int> &visited){
        visited.insert(node);
        result.push_back(node);
        for(auto neigh : adj[node]){
            if(!visited.count(neigh)) f(adj, neigh, result, visited);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        unordered_set<int> visited;
        for(int i = 0; i < V; i++){
            if(!visited.count(i)){
                f(adj, i, result, visited);
            }
        }

        return result;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        unordered_set<int> visited;

        queue<int> q;
        q.push(0);
        visited.insert(0);

        while(q.size()){
            int node = q.front(); q.pop();
            result.push_back(node);

            for(auto neigh : adj[node]){
                if(!visited.count(neigh)){
                    visited.insert(neigh);
                    q.push(neigh);
                }
            }
        }
        return result;
    }
};


int main() {

    return 0;
}