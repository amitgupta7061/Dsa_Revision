#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = nums.size() - 1; i >= 0; i -= 2){
            result += min(nums[i], nums[i-1]);
        }
        return result;
    }
};

int main() {

    return 0;
}