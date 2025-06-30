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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q; q.push(root);

        while(q.size()){
            vector<int> temp;
            for(int i = q.size(); i > 0; i--){
                TreeNode* node = q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(temp);
        }
        for(int i = 0; i < result.size(); i++){
            if(i % 2){
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};


int main() {

    return 0;
}