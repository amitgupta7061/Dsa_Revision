#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> morrisPreorder(TreeNode* root) {
    TreeNode* curr = root;
    vector<int> result;
    while (curr) {
        if (curr->left == NULL) {
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                result.push_back(curr->val);
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return result;
}



int main() {

    return 0;
}