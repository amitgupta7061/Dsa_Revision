#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        for(int i = 1; i <= n; i++) result += to_string(i);
        while(--k){
            next_permutation(result.begin(), result.end());
        }
        return result;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact *= i;
    }

    k--; // 0-based index
    string result = "";

    for (int i = 0; i < n; i++) {
        fact /= (n - i);
        int index = k / fact;
        result += to_string(nums[index]);
        nums.erase(nums.begin() + index);
        k %= fact;
    }

    return result;
}

};

int main() {

    return 0;
}