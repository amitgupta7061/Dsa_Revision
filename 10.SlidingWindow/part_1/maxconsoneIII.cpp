#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeroCnt = 0, result = 0, n = nums.size();
        while(r < n){
            if(nums[r]) r++;
            else {
                if(zeroCnt < k){
                    zeroCnt++ ; r++;
                } else {
                    result = max(result, r - l);
                    while(nums[l]) l++;
                    l++; r++;
                }
            }
        }
        result = max(result, r - l);
        return result;
    }
};


int main() {

    return 0;
}