#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> prime(n, true);

        prime[0] = false;
        if (n > 1) prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) prime[j] = false;
            }
        }

        long long sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            if (prime[i]) sum_a += nums[i];
            else sum_b += nums[i];
        }

        return abs(sum_a - sum_b);
    }
};


int main() {

    return 0;
}