#include <bits/stdc++.h>
using namespace std;


int dfs(int src, int parent, vector<int> adj[], vector<vector<int>> &dp){
    int notmatched = 0;

    for(auto neigh : adj[src]){
        if(neigh == parent) continue;
        dfs(neigh, src, adj, dp);
        notmatched += max(dp[neigh][0], dp[neigh][1]);
    }

    
}

int main() {

    int n;
    cin >> n;

    vector<int> adj[n+1];
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(1, 0, adj, dp);

    return 0;
}