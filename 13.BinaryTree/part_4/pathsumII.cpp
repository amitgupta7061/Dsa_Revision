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
    void f(TreeNode* root, int k, vector<int> &temp, vector<vector<int>> &result){
        if(!root) return;
        temp.push_back(root->val);
        k -= root->val;

        if(root->left == NULL and root->right == NULL){
            if(k == 0) result.push_back(temp);
        } else {
            if(root->left) f(root->left, k, temp, result);
            if(root->right) f(root->right, k, temp, result);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        f(root, targetSum, temp, result);
        return result;
    }
};

int main() {

    return 0;
}