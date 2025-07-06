#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int vertex, int edge, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[vertex];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> result(vertex, INT_MAX);
        result[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        while(pq.size()){
            auto [curr, dist] = pq.top(); pq.pop();
            for(auto [neigh, weight] : adj[curr]){
                if(dist + weight < result[neigh]){
                    result[neigh] = dist + weight;
                    pq.push({neigh, result[neigh]});
                }
            }
        }
        for(int i = 0; i < vertex; i++){
            if(result[i] == INT_MAX) result[i] = -1;
        }
        return result;
    }
};


int main() {

    return 0;
}