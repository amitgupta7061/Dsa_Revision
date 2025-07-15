#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), result = nums[0], maxfar = nums[0], minfar = nums[0];

        for(int i = 1; i < n; ++i) {
            if(nums[i] < 0) swap(maxfar, minfar);

            maxfar = max(nums[i], maxfar * nums[i]);
            minfar = min(nums[i], minfar * nums[i]);

            result = max(result, maxfar);
        }

        return result;
    }
};


int main() {

    return 0;
}