#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> map;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> result;
        q.push({root, {0, 0}});
        while(q.size()){
            auto curr = q.front(); q.pop();
            int x = curr.second.first, y = curr.second.second, val = curr.first->val;
            map[x][y].insert(val);

            if(curr.first->left) q.push({curr.first->left, {x-1, y+1}});
            if(curr.first->right) q.push({curr.first->right, {x+1, y+1}});
        }

        for (auto &col : map) {
            vector<int> temp;
            for (auto &row : col.second) {
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            result.push_back(temp);
        }

        return result;
    }
};

int main() {

    return 0;
}