#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n], lowTime(n , 0), discovery(n, 0);
        for(auto &it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> criticaledges;
        int currTime = 0;

        function<void(int, int)> f = [&](int node, int parent){
            discovery[node] = lowTime[node] = ++currTime;

            for(int &neigh : adj[node]){
                if(neigh == parent) continue;
                if(discovery[neigh] == 0){ // not visited
                    f(neigh, node);
                    lowTime[node] = min(lowTime[node], lowTime[neigh]);

                    if(lowTime[neigh] > discovery[node]){
                        criticaledges.push_back({node, neigh});
                    }
                } else {  // visited
                    lowTime[node] = min(lowTime[node], lowTime[neigh]);
                }
            }
        };

        f(0, -1);
        return criticaledges;
    }
};

int main() {

    return 0;
}