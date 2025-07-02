#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<vector<int>> preInPostTraversal(TreeNode* root) {
    vector<int> pre, in, post;
    if (root == NULL) return {};

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top(); st.pop();

        if (it.second == 1) {  // pre
            pre.push_back(it.first->val);
            it.second = 2;
            st.push(it); 
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2) {  // in
            in.push_back(it.first->val);
            it.second = 3;
            st.push(it);
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        else {  // post
            post.push_back(it.first->val);
        }
    }

    vector<vector<int>> result = {{pre}, {in}, {post}};
    return result;
}


int main() {

    return 0;
}