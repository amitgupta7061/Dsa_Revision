#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void topo(vector<vector<int>>& conditions, vector<int> &answer, int &k){
        vector<int> adj[k], indegree(k);
        for(auto &it : conditions){
            int u = it[0] - 1, v = it[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < k; i++) if(!indegree[i]) q.push(i);

        while(q.size()){
            int u = q.front(); q.pop();
            answer.push_back(u);
            for(int v : adj[u]) if(--indegree[v] == 0) q.push(v);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> result(k, vector<int>(k, 0));

        vector<int> topo_from_row, topo_from_col;
        topo(rowConditions, topo_from_row, k);
        topo(colConditions, topo_from_col, k);

        if(topo_from_row.size() != k or topo_from_col.size() != k) return {};

        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                if(topo_from_row[i] == topo_from_col[j]) 
                    result[i][j] = topo_from_row[i] + 1;

        return result;
    }
};

int main() {

    return 0;
}