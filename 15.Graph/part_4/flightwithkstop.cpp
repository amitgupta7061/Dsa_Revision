#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr = pair<int, pair<int, int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pairr, vector<pairr>, greater<pairr>> pq;
        vector<int> cost(n, 1e9);
        pq.push({0, {src, 0}});  // steps , node, dist
        cost[src] = 0;

        while(not pq.empty()){
            auto temp = pq.top(); pq.pop();
            int steps = temp.first, node = temp.second.first, dist = temp.second.second;

            for(auto [neigh, weight] : adj[node]){
                if(dist + weight < cost[neigh] and steps <= k){
                    cost[neigh] = dist + weight;
                    pq.push({steps+1, {neigh, cost[neigh]}});
                }
            }
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};

int main() {

    return 0;
}