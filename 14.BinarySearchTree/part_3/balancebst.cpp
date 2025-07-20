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
    void inorder(TreeNode* root, vector<int> &in){
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode* buildTree(vector<int> &in, int l, int r){
        if(l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = buildTree(in, l, mid - 1);
        root->right = buildTree(in, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);

        return buildTree(in, 0, in.size() - 1);
    }
};

int main() {

    return 0;
}