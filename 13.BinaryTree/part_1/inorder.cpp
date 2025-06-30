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
    void f(TreeNode* root, vector<int> &result){
        if(!root) return;
        f(root->left, result);
        result.push_back(root->val);
        f(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        f(root, result);
        return result;
    }
};

int main() {

    return 0;
}