#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0, sum = 0, n = nums.size();
        double maxi = 0;
        while(r < n){
            sum += nums[r];
            if(r - l + 1 == k){
                maxi = max(maxi, (sum * 1.0) / (k * 1.0));
                sum -= nums[l]; l++;
            }
            r++;
        }
        return maxi;
    }
};

int main() {

    return 0;
}