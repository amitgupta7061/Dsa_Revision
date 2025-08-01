#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> adj[], int node, int parent, vector<bool>& hasApple){
        int time = 0;
        for(int neigh : adj[node]){
            if(neigh == parent) continue;
            int fromchild = f(adj, neigh, node, hasApple);

            if(fromchild > 0 or hasApple[neigh]){
                time += fromchild + 2;
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return f(adj, 0, -1, hasApple);
    }
};

int main() {

    return 0;
}