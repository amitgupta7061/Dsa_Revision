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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        set<int> st;
        while(q.size() > 0){
           TreeNode* curr = q.front(); q.pop();
           int rem = k - curr->val;
           if(st.count(rem)) return true;
           if(curr->left)  q.push(curr->left);
           if(curr->right) q.push(curr->right);
           st.insert(curr->val); 
        }
        return false;
    }
};

int main() {

    return 0;
}