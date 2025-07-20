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
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};


int main() {

    return 0;
}