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
    void inorder(TreeNode* root, TreeNode* &curr){
        if(!root) return;
        inorder(root->left, curr);

        root->left = NULL;
        curr->right = root;
        curr = root;

        inorder(root->right, curr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        TreeNode* curr = res;

        inorder(root, curr);
        return res->right;
    }
};

int main() {

    return 0;
}