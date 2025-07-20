#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    void buildComb(int n) { // Triangle .. 
        comb.resize(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
    }

    long long countWays(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long leftWays = countWays(left);
        long long rightWays = countWays(right);
        long long ways = (comb[n-1][left.size()] * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        buildComb(n);
        return (countWays(nums) - 1 + MOD) % MOD; 
    }
};


int main() {

    return 0;
}