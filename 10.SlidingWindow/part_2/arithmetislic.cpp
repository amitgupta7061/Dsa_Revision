#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int result = 0, cnt = 0;
        for(int i = 2 ; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                cnt++;
                result += cnt;
            } else cnt = 0;
        }
        return result;
    }
};

int main() {

    return 0;
}