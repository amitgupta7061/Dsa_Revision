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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int mini = INT_MAX, level = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            for(int i = q.size(); i > 0; i--){
                TreeNode* node = q.front(); q.pop();
                if(!node->left and !node->right){
                    mini = min(mini, level);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return mini;
    }
};

int main() {

    return 0;
}