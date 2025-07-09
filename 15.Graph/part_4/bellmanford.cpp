#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<int> bellmanford(vector<vector<int>> &edges, int v, int src){
        vector<int> distance(v, 1e8);
        distance[src] = 0;
        for(int i = 0; i < v - 1; i++){
            for(auto it : edges){
                int u = it[0], v = it[1], w = it[2];
                if(distance[u] != 1e8 and distance[u] + w < distance[v]){
                    distance[v] = distance[u] + w;
                }
            }
        }
        for(auto it : edges){ // Negative cycle
            int u = it[0], v = it[1], w = it[2];
            if(distance[u] != 1e8 and distance[u] + w < distance[v]){
                return {-1};
            }
        }
    }
};

int main() {

    return 0;
}