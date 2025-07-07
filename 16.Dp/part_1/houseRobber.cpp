#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int ind, vector<int> &dp){
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(nums[ind] + f(nums, ind+2, dp), f(nums, ind+1, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums, 0, dp);
    }
};

int main() {

    return 0;
}