#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    void f(TreeNode* root){
        for(;root; st.push(root), root = root->left);
    }
    BSTIterator(TreeNode* root) {
        f(root);
    }
    
    int next() {
        TreeNode* node = st.top(); st.pop();
        f(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.size();
    }
};


int main() {

    return 0;
}