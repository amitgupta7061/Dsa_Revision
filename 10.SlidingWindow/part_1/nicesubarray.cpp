#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int k){
        int l = 0, r = 0, result = 0, oddcnt = 0, n = nums.size();
        while(r < n){
            oddcnt += nums[r] % 2;
            while(oddcnt > k){
                oddcnt -= nums[l] % 2; l++;
            }
            result += r - l + 1;
            r++;
        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};

int main() {

    return 0;
}