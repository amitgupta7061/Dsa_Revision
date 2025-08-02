#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find_parent(int node){
        if(node == parent[node]) return node;
        return parent[node] = find_parent(parent[node]);
    }
    void union_by_size(int u, int v){
        int parent_u = find_parent(u), parent_v = find_parent(v);

        if(parent_u == parent_v) return;
        if(size[parent_u] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        } else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v]; 
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet D(n * n);
        

    }
};

int main() {

    return 0;
}