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
    int f(TreeNode* root, int &maxsum){
        if(!root) return 0;
        int left = max(0, f(root->left, maxsum));
        int rght = max(0, f(root->right, maxsum));

        maxsum = max(maxsum, root->val + left + rght);
        return root->val + max(left, rght);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        f(root, maxsum);
        return maxsum;
    }
};

int main() {

    return 0;
}