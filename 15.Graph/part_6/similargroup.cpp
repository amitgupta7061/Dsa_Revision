#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConnect(string &s1, string &s2){
        int diffCnt = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) diffCnt++;
        }
        return diffCnt == 0 or diffCnt == 2;
    }
    void f(vector<int> adj[], int node, vector<int> &visited){
        visited[node] = 1;
        for(int &neigh : adj[node]){
            if(!visited[neigh]) f(adj, neigh, visited);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> adj[n], visited(n, 0);
        for(int u = 0; u < n; u++){
            for(int v = u + 1; v < n; v++){
                if(canConnect(strs[u], strs[v])){
                    adj[u].push_back(v);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++;
                f(adj, i, visited);
            }
        }

        return cnt;
    }
};

int main() {

    return 0;
}