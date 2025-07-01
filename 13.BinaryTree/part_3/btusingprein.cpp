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
    TreeNode* f(vector<int> &pre, vector<int> &in, int str, int end, int &ind){
        if(str > end) return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        int i = str;
        for(i = str; i <= end; i++) if(pre[ind] == in[i]) break;
        ind++;
        root->left  = f(pre, in, str, i-1, ind);
        root->right = f(pre, in, i+1, end, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0, n = preorder.size();
        return f(preorder, inorder, 0, n-1, ind);
    }
};

int main() {

    return 0;
}