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
    int isSumProperty(TreeNode* root) {
        if(!root || (!root->left and !root->right)) return 1;
        int left = isSumProperty(root->left);
        int rght = isSumProperty(root->right);
        if(root->val != left + rght) return 0; 
        return isSumProperty(root->left) and isSumProperty(root->right);
    }
};


int main() {

    return 0;
}