#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> &nums, int &maxi, int &cnt, int ind, int curr_or) {
        if (ind == nums.size()) {
            if (curr_or == maxi) cnt++;
            return;
        }

        f(nums, maxi, cnt, ind + 1, curr_or);
        f(nums, maxi, cnt, ind + 1, curr_or | nums[ind]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0, cnt = 0;

        for (int x : nums) maxi |= x;
        f(nums, maxi, cnt, 0, 0);
      
        return cnt;
    }
};

int main() {

    return 0;
}