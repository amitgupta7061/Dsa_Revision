#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); k--;
        while(k--){
            pq.pop();
        }
        return pq.size() ? pq.top() : -1;
    }
};

int main() {

    return 0;
}