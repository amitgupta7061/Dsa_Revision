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
    int ind = 0;
    void Inorder(TreeNode* root, vector<int> &in, bool fill){
        if(!root) return;
        Inorder(root->left, in, fill);
        if(!fill) in.push_back(root->val);
        else root->val = in[ind++];
        Inorder(root->right, in, fill);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> in;
        Inorder(root, in, false);
        for(int i = in.size() - 2; i >= 0; i--){
            in[i] = in[i] + in[i+1];
        }
        Inorder(root, in, true);
        return root;
    }
};

int main() {

    return 0;
}