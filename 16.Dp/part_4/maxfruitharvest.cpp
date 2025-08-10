#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), ans = 0, i = 0, j = 0;
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + fruits[i][1];

        while (j < n) {
            int left = fruits[i][0], right = fruits[j][0];
            int steps = min(abs(startPos - left) + (right - left),
                            abs(startPos - right) + (right - left));
            if (steps <= k) {
                ans = max(ans, prefix[j + 1] - prefix[i]);
                ++j;
            } else {
                ++i;
            }
        }

        return ans;
    }
};



int main() {

    return 0;
}