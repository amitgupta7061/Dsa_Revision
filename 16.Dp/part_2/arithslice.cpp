#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), total = 0;
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];
                int count_at_j = dp[j][diff];
                dp[i][diff] += count_at_j + 1;

                total += count_at_j;
            }
        }

        return total;
    }
};


int main() {

    return 0;
}