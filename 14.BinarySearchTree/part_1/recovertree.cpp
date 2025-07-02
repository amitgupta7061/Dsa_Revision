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
    void f(TreeNode* root, vector<TreeNode*> &positions){
        if(root == NULL) return;
        f(root->left, positions);
        if(positions[0] and root->val < positions[0]->val){
            if(positions[1] == NULL){
                positions[1] = positions[0];
                positions[2] = root;
            } else positions[3] = root;
        }
        positions[0] = root;
        f(root->right, positions);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> positions(4, NULL); // prev, first, middle, last
        f(root, positions);
        if(positions[1] and positions[3]) swap(positions[1]->val, positions[3]->val);
        else if(positions[1] and positions[2]) swap(positions[1]->val, positions[2]->val);
    }
};


int main() {

    return 0;
}