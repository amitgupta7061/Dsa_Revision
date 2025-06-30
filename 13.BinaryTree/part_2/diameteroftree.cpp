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
    int f(TreeNode* root, int &maxdiameter){
        if(!root) return 0;
        int left = f(root->left, maxdiameter);
        int rght = f(root->right, maxdiameter);

        maxdiameter = max(maxdiameter, left + rght);
        return 1 + max(left, rght);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdiameter = 0;
        f(root, maxdiameter);
        return maxdiameter;
    }
};

int main() {

    return 0;
}