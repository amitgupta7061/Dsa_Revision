#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> graph[n];
        vector<int> indegree(n, 0);
        for(auto &it : relations){
            int u = it[0] - 1, v = it[1] - 1;
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);

        int result = 0;
        while (!q.empty()) {
            int sz = q.size(), take = min(k, sz); 
            result++;

            vector<int> next;
            for (int i = 0; i < take; i++) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (--indegree[v] == 0) next.push_back(v);
                }
            }

            int remaining = sz - take;
            queue<int> temp;
            for (int i = 0; i < remaining; i++) {
                temp.push(q.front()); q.pop();
            }
            for (int x : next) temp.push(x);
            swap(q, temp);
        }

        return result;
    }
};

int main() {

    return 0;
}