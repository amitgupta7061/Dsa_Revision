#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int parent_u = findParent(u), parent_v = findParent(v); // ultimate parent
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet D(n);
        int connectedcomp = 0, extraedge = 0;
        for(auto it : connections){
            if(D.findParent(it[0]) == D.findParent(it[1])) extraedge++;
            else D.unionBySize(it[0], it[1]);
        }
        for(int i = 0; i < n; i++){
            if(D.parent[i] == i) connectedcomp++;
        }
        return connectedcomp-1 <= extraedge ? connectedcomp - 1 : -1;
    }
};

int main() {

    return 0;
}