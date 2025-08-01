#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findminCharDFS(unordered_map<char, vector<char>> &graph, char src, vector<bool> &visited){
        visited[src - 'a'] = true;
        char minChar = src;
        for(auto &neigh : graph[src]){
            if(!visited[neigh - 'a']){
                minChar = min(minChar, findminCharDFS(graph, neigh, visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.length(), n = baseStr.length();
        unordered_map<char, vector<char>> graph;
        for(int i = 0; i < m; i++){
            graph[s1[i]].push_back(s2[i]);
            graph[s2[i]].push_back(s1[i]);
        }
        string result;
        for(int i = 0; i < n; i++){
            vector<bool> visited(26, false);
            result.push_back(findminCharDFS(graph, baseStr[i], visited));
        }
        return result;
    }
};

int main() {

    return 0;
}