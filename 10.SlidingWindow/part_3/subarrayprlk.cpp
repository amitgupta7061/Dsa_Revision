#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int product = 1, l = 0, r = 0, result = 0, n = nums.size();

        while(r < n){
            product *= nums[r];
            while(l < n and product >= k){
                product /= nums[l]; l++;
            }
            if(l == n) break;
            result += r - l + 1;
            r++;
        }

        return result;
    }
};

int main() {

    return 0;
}