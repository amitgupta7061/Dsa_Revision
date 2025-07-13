#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
            if(dq.size() and dq.front() <= i - k) dq.pop_front();
            if(dq.size() and nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main() {

    return 0;
}