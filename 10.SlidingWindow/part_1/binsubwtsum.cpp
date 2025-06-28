#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int goal){
        if(goal < 0) return 0;
        int l = 0, r = 0, sum = 0, n = nums.size(), cnt = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal) {
                sum -= nums[l]; l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums,goal-1);
    }
};

int main() {

    return 0;
}