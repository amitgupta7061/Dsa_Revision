#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> result(n), subtreesize(n);

        function<void(int, int, int)> calculatedistance = [&](int node, int parent, int depth){
            result[0] += depth;
            subtreesize[node] = 1;
            
        };
    }
};


int main() {

    return 0;
}