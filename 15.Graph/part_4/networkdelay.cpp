#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> time(n+1, 1e9);
        time[k] = 0; time[0] = -1;
        pq.push({0, k});

        while(pq.size()){
            auto [taken, node] = pq.top(); pq.pop();

            for(auto [neigh, weight] : adj[node]){
                if(taken + weight < time[neigh]){
                    time[neigh] = taken + weight;
                    pq.push({time[neigh], neigh});
                }
            }
        }

        int maxi = -1;
        for(auto it : time) maxi = max(maxi, it);

        return maxi == 1e9 ? -1 : maxi;
    }
};

int main() {

    return 0;
}