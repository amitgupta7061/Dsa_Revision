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
    int f(TreeNode* root){
        if(!root) return 0;
        int left = f(root->left);
        if(left == -1) return -1;
        int rght = f(root->right);
        if(rght == -1) return -1;
        if(abs(left - rght) > 1) return -1;
        return 1 + max(left, rght);
    }
    bool isBalanced(TreeNode* root) {
        return f(root) == -1 ? false : true;
    }
};

int main() {

    return 0;
}