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
    TreeNode* findpred(TreeNode* root, int key) {
        TreeNode* pred = NULL;
        while(root) {
            if(root->val < key) {
                pred = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred;
    }

    TreeNode* findsucc(TreeNode* root, int key) {
        TreeNode* succ = NULL;
        while(root) {
            if(root->val > key) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }

    vector<TreeNode*> findPreSuc(TreeNode* root, int key) {
        TreeNode* pred = findpred(root, key);
        TreeNode* succ = findsucc(root, key);
        return {pred, succ};
    }
};


int main() {

    return 0;
}