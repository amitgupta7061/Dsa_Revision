#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxintCanReach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxintCanReach) return false;
            maxintCanReach = max(maxintCanReach, i + nums[i]);
        }
        return true;
    }
};

int main() {

    return 0;
}