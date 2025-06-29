#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, currpos = 0, maxGo = 0;
        for(int i = 0; i < nums.size()-1; i++){
            maxGo = max(maxGo, i + nums[i]);
            if(i == currpos){
                steps++; currpos = maxGo;
            }
        }
        return steps;
    }
};

int main() {

    return 0;
}