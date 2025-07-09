#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, -1));
        for(auto it : edges){
            int u = it[0], v = it[1], w = it[2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == -1) mat[i][j] = 1e9;
                if(i == j) mat[i][j] = 0;
            }
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int result = -1, minReachable = n;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; ++j){
                if(i != j && mat[i][j] <= distanceThreshold)
                    count++;
            }
            if(count <= minReachable){
                minReachable = count;
                result = i;
            }
        }
        return result;
    }
};

int main() {

    return 0;
}