#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr =  pair<long long, long long>;
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pairr> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pairr, vector<pairr>, greater<>> pq; 
        long long mod = (long long)(1e9 + 7); 
        vector<long long> dist(n, 1e15), ways(n, 0);
        dist[0] = 0; ways[0] = 1;
        pq.push({0, 0});

        while(pq.size()){
            auto [distance, node] = pq.top(); pq.pop();
            for(auto [neigh, weight] : adj[node]){
                if(distance + weight < dist[neigh]){
                    dist[neigh] = distance + weight;
                    pq.push({dist[neigh], neigh});
                    ways[neigh] = ways[node];
                } else if(distance + weight == dist[neigh]){
                    ways[neigh] = (ways[neigh] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

int main() {

    return 0;
}