#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i = 0;

        while(i < n){
            if(nums[i] <= 0) i++;
            else if(nums[i] == i+1 or nums[i] > n or nums[i] == nums[nums[i] - 1]) i++;
            else swap(nums[i], nums[nums[i] - 1]);
        }

        for(i = 0; i < n; i++){
            if(nums[i] != i+1) return i + 1;
        }
        return n + 1;
    }
};


int main() {

    return 0;
}