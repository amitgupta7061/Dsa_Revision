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
    void inOrder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }

    vector<int> merge(const vector<int>& list1, const vector<int>& list2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) {
                merged.push_back(list1[i++]);
            } else {
                merged.push_back(list2[j++]);
            }
        }
        while (i < list1.size()) merged.push_back(list1[i++]);
        while (j < list2.size()) merged.push_back(list2[j++]);
        return merged;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        inOrder(root1, list1);
        inOrder(root2, list2);
        return merge(list1, list2);
    }
};


int main() {

    return 0;
}