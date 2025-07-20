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
    int maxSum = 0;
    vector<int> dfs(TreeNode* root) {
        if (!root) return {1, INT_MAX, INT_MIN, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool isBST = left[0] && right[0] && root->val > left[2] && root->val < right[1];

        if (isBST) {
            int sum = root->val + left[3] + right[3];
            maxSum = max(maxSum, sum);
            return {1, min(root->val, left[1]), max(root->val, right[2]), sum};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};


int main() {

    return 0;
}