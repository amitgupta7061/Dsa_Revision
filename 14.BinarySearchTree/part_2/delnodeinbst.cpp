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
    TreeNode* inorderpredecessor(TreeNode* root){
        TreeNode* pre = root->left;
        while(pre->right) pre = pre->right;
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left == NULL and root->right == NULL){
                return NULL;
            } else if(root->left == NULL or root->right == NULL){
                if(root->left == NULL) return root->right;
                else return root->left;
            } else {
                TreeNode* pre = inorderpredecessor(root);
                root->val = pre->val;
                root->left = deleteNode(root->left, pre->val);
            }
        } 
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);

        return root;
    }
};

int main() {

    return 0;
}