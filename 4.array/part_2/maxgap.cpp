#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxgap = 0;
        for(int i = 1; i < nums.size(); i++){
            maxgap = max(maxgap, abs(nums[i] - nums[i-1]));
        }
        return maxgap;
    }
};

int main() {

    return 0;
}