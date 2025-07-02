#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class SOlution{
    int findCeil(TreeNode* root, int input) {
        int result = -1;
        while(root){
            if(root->val == input) return root->val;
            if(root->val > input){
                result = root->val;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return result;
    }
};


int main() {

    return 0;
}