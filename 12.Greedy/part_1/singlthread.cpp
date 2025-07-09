#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pairr = pair<int, pair<int, int>>;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end());

        int startTime = tasks[0][0];
        priority_queue<pairr, vector<pairr>, greater<>> pq;
        for(int i = 0; i < tasks.size(); i++){
            pq.push({tasks[i][1], {tasks[i][0], i}});
        }

        while(pq.size()){
            
        }
    }
};


int main() {

    return 0;
}