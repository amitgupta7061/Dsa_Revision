#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(const vector<int>& candidates, int ind, int target, vector<int>& path,
                        vector<vector<int>>& result) {

        if (target < 0) return;
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = ind; i < candidates.size(); ++i) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], path, result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, result);
        return result;
    }
};

int main() {

    return 0;
}