#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1){
            int weightof_first = pq.top(); pq.pop();
            int weightof_secnd = pq.top(); pq.pop();

            if(weightof_first == weightof_secnd) continue;
            else pq.push(abs(weightof_first - weightof_secnd));
        }

        return pq.size() ? pq.top() : 0;
    }
};

int main() {

    return 0;
}