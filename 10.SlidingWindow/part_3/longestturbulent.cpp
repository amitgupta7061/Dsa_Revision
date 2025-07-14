#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int l = 0, result = 1;
        char prevopr = '#';

        for (int r = 1; r < n; ++r) {
            if (nums[r] > nums[r - 1]) {
                if (prevopr == '#' || prevopr == '<') {
                    prevopr = '>';
                } else {
                    l = r - 1;
                    prevopr = '>';
                }
            } else if (nums[r] < nums[r - 1]) {
                if (prevopr == '#' || prevopr == '>') {
                    prevopr = '<';
                } else {
                    l = r - 1;
                    prevopr = '<';
                }
            } else {
                l = r;
                prevopr = '#';
            }
            result = max(result, r - l + 1);
        }

        return result;
    }
};


int main() {

    return 0;
}