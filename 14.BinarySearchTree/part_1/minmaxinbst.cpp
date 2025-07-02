#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    int mininbst(TreeNode* root) {
        if (!root) return -1;
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }

    int maxinbst(TreeNode* root) {
        if (!root) return -1;
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }
};


int main() {

    return 0;
}