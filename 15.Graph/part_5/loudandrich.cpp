#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n], indegree(n, 0), result(n);

        for(auto &it : richer){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }


        queue<int> q;
        for(int i = 0; i < n; i++) {
            result[i] = i; 
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v : adj[u]){
                if(quiet[result[u]] < quiet[result[v]]){
                    result[v] = result[u];
                }

                if(--indegree[v] == 0) q.push(v);
            }
        }

        return result;
    }
};


int main() {

    return 0;
}