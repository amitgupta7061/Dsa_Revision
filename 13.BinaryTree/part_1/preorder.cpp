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
    void f(TreeNode* root, vector<int> &result){
        if(!root) return;
        result.push_back(root->val);
        f(root->left, result);
        f(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        f(root, result);
        return result;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()){
            TreeNode* curr = st.top(); st.pop();
            result.push_back(curr->val);
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return result;
    }
};

int main() {

    return 0;
}