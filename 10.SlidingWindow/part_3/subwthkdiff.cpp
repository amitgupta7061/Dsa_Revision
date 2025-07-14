#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int l = 0, result = 0;
        unordered_map<int, int> freq;

        for (int r = 0; r < nums.size(); ++r) {
            if (freq[nums[r]]++ == 0) k--;

            while (k < 0) {
                if (--freq[nums[l]] == 0) k++;
                l++;
            }

            result += r - l + 1;
        }

        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};


int main() {

    return 0;
}