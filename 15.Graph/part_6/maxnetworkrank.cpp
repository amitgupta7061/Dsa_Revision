#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto &it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int maxi = 0;

        function<bool(int, int)> f = [&](int u, int v){
            for(auto it : adj[u]){
                if(it == v) return true;
            }
            return false;
        };

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int temp = adj[i].size() + adj[j].size() - f(i, j) ? 1  : 0;
                maxi = max(maxi, temp);
            }
        }

        return maxi;
    }
};

int main() {

    return 0;
}