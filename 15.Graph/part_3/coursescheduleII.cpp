#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int> graph[], vector<int> &visited, vector<int> &ancestor, int node, vector<int> &result){
        visited[node] = 1; ancestor[node] = 1;
        for(auto neigh : graph[node]){
            if(!visited[neigh]){
                if(f(graph, visited, ancestor, neigh, result)) return true;
            } else{
                if(ancestor[neigh]) return true;
            }
        }
        ancestor[node] = 0;
        result.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> visited(numCourses, 0), ancestor(numCourses, 0), result;
        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!visited[i] and f(graph, visited, ancestor, i, result)) return {};
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> result, Indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]) Indegree[it]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(Indegree[i] == 0) q.push(i);
        }

        while(q.size()){
            int node = q.front(); q.pop();
            result.push_back(node);

            for(auto neigh : adj[node]){
                Indegree[neigh]--;
                if(Indegree[neigh] == 0) q.push(neigh);
            }
        }
        if (result.size() != numCourses) return {};
        return result;
    }
};

int main() {

    return 0;
}