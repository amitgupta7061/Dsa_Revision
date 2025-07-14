#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(int n, int total, vector<int>& result, unordered_set<int>& seen) {
        if (result.size() == total) {
            // Check if first and last differ by one bit
            int diff = result[0] ^ result.back();
            return (diff && !(diff & (diff - 1)));  // power of 2 check
        }

        int current = result.back();
        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i); // flip one bit
            if (seen.count(next)) continue;
            seen.insert(next);
            result.push_back(next);

            if (backtrack(n, total, result, seen)) return true;

            seen.erase(next);
            result.pop_back();
        }
        return false;
    }

    vector<int> grayCode(int n) {
        vector<int> result = {0};
        unordered_set<int> seen = {0};
        int total = 1 << n; // 2^n

        backtrack(n, total, result, seen);
        return result;
    }
};


int main() {

    return 0;
}