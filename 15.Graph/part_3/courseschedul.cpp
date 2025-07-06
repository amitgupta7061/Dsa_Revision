#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFS(vector<int> adj[], int src, vector<bool> &visited, vector<bool> &ancestor){
        visited[src]  = true;
        ancestor[src] = true;   
        for(auto neigh : adj[src]){
            if(!visited[neigh]){
                if(DFS(adj, neigh, visited, ancestor)) return true;
            } else if(ancestor[neigh]){
                return true;
            }
        }
        ancestor[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> visited(numCourses, false), ancestor(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] and DFS(adj, i, visited, ancestor)) return false;
        }

        return true;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>Indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) Indegree[it]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(Indegree[i] == 0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;
            for(auto neigh : adj[node]) {
                  Indegree[neigh]--;
                  if(Indegree[neigh] == 0) q.push(neigh);
            }
        }

        return cnt == numCourses;
    }
};

int main() {

    return 0;
}