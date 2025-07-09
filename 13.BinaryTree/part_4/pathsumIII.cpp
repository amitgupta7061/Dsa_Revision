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
    bool hashsum(TreeNode* root, int target){
        if(!root) return false;
        if(root->val == target) return true;
        return hashsum(root->left, target-root->val) or hashsum(root->right, target-root->val);
    }
    void f(TreeNode* root, int target, int &cnt){
        if(!root) return;
        if(hashsum(root, target)) cnt++;
        f(root->left, target, cnt);
        f(root->right, target, cnt);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        f(root, targetSum, cnt);
        return cnt;
    }
};


int main() {

    return 0;
}