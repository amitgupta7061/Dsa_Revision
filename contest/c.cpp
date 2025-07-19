#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr = pair<long long, int>;
    bool f(int n, vector<pair<int, int>> graph[], vector<bool>& online, long long k, int lim) {
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        priority_queue<pairr, vector<pairr>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curr_cost, curr_node] = pq.top(); pq.pop();
            if (curr_cost > dist[curr_node]) continue;
            for (auto [neigh, weight] : graph[curr_node]) {
                if (weight < lim) continue;
                if (!online[neigh] && neigh != n - 1) continue;
                if (dist[neigh] > dist[curr_node] + weight) {
                    dist[neigh] = dist[curr_node] + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(), maxi = 0;
        vector<pair<int, int>> graph[n];
        for (auto it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
            maxi = max(maxi, it[2]);
        }

        int low = 0, high = maxi, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (f(n, graph, online, k, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};


int main() {

    return 0;
}