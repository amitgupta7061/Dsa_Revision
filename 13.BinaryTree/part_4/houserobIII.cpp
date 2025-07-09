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
    unordered_map<TreeNode*, int> dp;

    int f(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (!root) return 0;
        if (dp.count(root)) return dp[root];

        int include = root->val;
        if (root->left) {
            include += f(root->left->left, dp);
            include += f(root->left->right, dp);
        }
        if (root->right) {
            include += f(root->right->left, dp);
            include += f(root->right->right, dp);
        }

        int exclude = f(root->left, dp) + f(root->right, dp);
        return dp[root] = max(include, exclude);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return f(root, dp);
    }
};


int main() {

    return 0;
}