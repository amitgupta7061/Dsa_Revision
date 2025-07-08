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
        int parent_u = findParent(u), parent_v = findParent(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int maxirow = -1, maxicol = -1;
        for(auto coord : stones){
            maxirow = max(maxirow, coord[0]);
            maxicol = max(maxicol, coord[1]);
        }

        DisjointSet D(maxirow + maxicol + 2);
        unordered_map<int, int> stoneNodes;

        for(auto it : stones){
            D.unionBySize(it[0], it[1] + maxirow + 1);
            stoneNodes[it[0]] = 1;
            stoneNodes[it[1]+maxirow+1] = 1;
        }

        int connectedComp = 0;
        for(auto it : stoneNodes){
            if(D.findParent(it.first) == it.first) connectedComp++;
        }

        return stones.size() - connectedComp;
    }
};

int main() {

    return 0;
}