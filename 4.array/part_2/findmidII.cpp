#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findmid(vector<int> &nums){
        int low = 0, high = nums.size() - 1;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == nums[high]) high--;
            else if(nums[mid] < nums[high]) high = mid;
            else low = mid + 1;
        }

        return nums[low];
    }
};

int main() {

    return 0;
}