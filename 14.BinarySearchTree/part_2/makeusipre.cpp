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
    void insert(TreeNode* root,int val){
    if((root->val)>val){
        if((root->left)==NULL) root->left = new TreeNode(val);
        else insert(root->left,val);
    }
    else{
        if((root->right)==NULL) root->right = new TreeNode(val);
        else insert(root->right,val);
    }
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++) insert(root,preorder[i]);
        return root;
    }
};


int main() {

    return 0;
}