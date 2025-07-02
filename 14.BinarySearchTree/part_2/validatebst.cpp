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
    int maxinTree(TreeNode* root){
        if(root == NULL) return INT_MIN;
        return max(root->val, max(maxinTree(root->left), maxinTree(root->right)));
    }
    int mininTree(TreeNode* root){
        if(root == NULL) return INT_MAX;
        return min(root->val, min(mininTree(root->left), mininTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root->val < maxinTree(root->left) or root->val > mininTree(root->right)) return false;
        return isValidBST(root->left) and isValidBST(root->right);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};


int main() {

    return 0;
}