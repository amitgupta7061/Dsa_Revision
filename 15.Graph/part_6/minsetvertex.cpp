#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], indegree(n, 0);
        for(auto &it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> result;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) result.push_back(i);
        }

        return result;
    }
};

int main() {

    return 0;
}