#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &isRecursion){
        visited[src]  = true;
        isRecursion[src] = true;   
        for(auto neigh : graph[src]){
            if(!visited[neigh]){
                if(DFS(graph, neigh, visited, isRecursion)) return true;
            } else if(isRecursion[neigh]){
                return true;
            }
        }
        isRecursion[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int vertex = graph.size();
        vector<bool> visited(vertex, false), isRecursion(vertex, false);
        vector<int> result;

        for(int i = 0; i < vertex; i++){
            DFS(graph, i, visited, isRecursion);
        }

        for(int i = 0; i < vertex; i++){
            if(!isRecursion[i]) result.push_back(i);
        }

        return result;
    }
};

int main() {

    return 0;
}