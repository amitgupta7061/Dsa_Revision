#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> adj[], int node, int parent, string &s, int &maxi){
        int longest = 0, s_longest = 0;
        for(int &neigh : adj[node]){
            if(neigh == parent) continue;
            int lenfromchild = f(adj, neigh, node, s, maxi);
            if(s[node] == s[neigh]) continue;

            if(lenfromchild > s_longest) s_longest = lenfromchild;
            if(s_longest > longest) swap(s_longest, longest);
        }

        int choose_anyone = max(longest, s_longest) + 1;
        int currLen = 1 + longest + s_longest;

        maxi = max({maxi, 1, choose_anyone, currLen});
        return max(choose_anyone, 1);
    }
    int longestPath(vector<int>& parent, string s) {
        vector<int> adj[parent.size()];
        for(int i = 1; i < parent.size(); i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int maxi = 0;
        f(adj, 0, -1, s, maxi);
        return maxi;
    }
};

int main() {

    return 0;
}