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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val or root->val == q->val) return root;
        TreeNode* lft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rgt = lowestCommonAncestor(root->right, p, q);

        if(lft == NULL) return rgt;
        else if(rgt == NULL) return lft;
        else return root;
    }
};

int main() {

    return 0;
}