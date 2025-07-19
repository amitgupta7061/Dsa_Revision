#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int k){
        int cnt = 0, result = 0;

        for(auto num : nums){
            num <= k ? cnt++ : cnt = 0;
            result += cnt;
        }

        return result;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return f(nums, right) - f(nums, left - 1);
    }
};

int main() {

    return 0;
}