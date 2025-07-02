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
    int floor(TreeNode* root, int x) {
        int result = -1;
        while(root){
            if(root->val == x) return x;
            if(root->val < x){
                result = root->val;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return result;
    }
};


int main() {

    return 0;
}