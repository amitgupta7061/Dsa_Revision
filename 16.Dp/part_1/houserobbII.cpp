#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int ind, int start, vector<int> &dp){
        if(ind < start) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(nums[ind] + f(nums, ind - 2, start, dp), f(nums, ind - 1, start, dp));
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()+1, -1);
        int temp = f(nums, nums.size() - 1, 1, dp);
        dp.clear();
        dp.resize(nums.size()+1, -1);
        return max(temp, f(nums, nums.size()-2, 0, dp));
    }
};
int main() {

    return 0;
}