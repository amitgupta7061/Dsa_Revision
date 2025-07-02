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
        f(root->left, result);
        f(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        f(root, result);
        return result;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> result;
        stack<TreeNode*> st1,st2;
        st1.push(root);

        while(st1.size()){
            auto node = st1.top(); st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }


        while(st2.size()){
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;
    }
};

int main() {

    return 0;
}