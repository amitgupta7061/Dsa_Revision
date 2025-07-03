#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, int src, unordered_set<int> &visited){
        visited.insert(src);
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[src][i] and !visited.count(i)) DFS(isConnected, i, visited); 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        unordered_set<int> visited;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited.count(i)){
                cnt++; DFS(isConnected, i, visited);
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}