#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n], color(n, -1);

        for (auto &it : dislikes) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<pair<int, int>> q;
                q.push({i, 0});
                color[i] = 0;

                while (!q.empty()) {
                    auto [u, col] = q.front(); q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = !col;
                            q.push({v, color[v]});
                        } else if (color[v] == col) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
    
    if (sol.possibleBipartition(n, dislikes))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
