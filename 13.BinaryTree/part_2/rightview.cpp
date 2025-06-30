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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        queue<pair<TreeNode*, int>> q; q.push({root, 1});
        while(q.size()){
            auto curr = q.front(); q.pop();
            if(result.size() == curr.second) result.back() = curr.first->val;
            else result.push_back(curr.first->val);

            if(curr.first->left) q.push({curr.first->left, curr.second+1});
            if(curr.first->right) q.push({curr.first->right, curr.second+1});
        }
        return result;
    }
};


int main() {

    return 0;
}