#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0, prev = 0;

        for (int curr = 1; curr < nums.size() - 1; ++curr) {
            if (nums[curr] == nums[curr + 1]) continue;
            if (nums[curr] > nums[prev] && nums[curr] > nums[curr + 1]) count++;
            if (nums[curr] < nums[prev] && nums[curr] < nums[curr + 1]) count++; 
            prev = curr;
        }
      
        return count;
    }
};

int main() {

    return 0;
}