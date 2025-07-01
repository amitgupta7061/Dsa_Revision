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
    TreeNode* f(vector<int> &in, vector<int> &pos, int str, int end, int &ind){
        if(str > end) return NULL;
        TreeNode* root = new TreeNode(pos[ind]);
        int i = str;
        for(i = str; i <= end; i++) if(in[i] == pos[ind]) break;
        ind--;
        root->right = f(in, pos, i+1, end, ind);
        root->left  = f(in, pos, str, i-1, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size(), ind = n - 1;
        return f(inorder, postorder, 0, n-1, ind);
    }
};

int main() {

    return 0;
}