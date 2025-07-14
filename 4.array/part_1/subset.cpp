#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> &nums, int ind, vector<int> &subset, vector<vector<int>> &result){
        result.push_back(subset);

        for(int i = ind; i < nums.size(); i++){
            subset.push_back(nums[i]);
            f(nums, i+1, subset, result);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        f(nums, 0, subset, result);
        return result;
    }
};

int main() {

    return 0;
}