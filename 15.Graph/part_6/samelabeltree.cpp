#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> adj[], int node, int parent, string &labels, vector<int> &result, vector<int> &count){
        char currlabel = labels[node];
        int cnt_before = count[currlabel - 'a'];
        count[currlabel - 'a'] += 1;

        for(int &neigh : adj[node]){
            if(neigh == parent) continue;
            f(adj, neigh, node, labels, result, count);
        }

        int cnt_after = count[currlabel - 'a'];
        result[node] = cnt_after - cnt_before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> result(n, 0), count(26, 0);
        f(adj, 0, -1, labels, result, count);
        return result;
    }
};

int main() {

    return 0;
}