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
    int findpred(TreeNode* root, int k){
        int pred = -1;
        while (root) {
            if (root->val < k) {
                pred = root->val; root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred;
    }
    int findsucc(TreeNode* root, int k){
        int succ = -1;
        while (root) {
            if (root->val > k) {
                succ = root->val; root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> result;
        for(auto &it : queries){
            result.push_back({findpred(root, it), findsucc(root, it)});
        }
        return result;
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorderList;
        inorder(root, inorderList);

        vector<vector<int>> result;

        for (int q : queries) {
            auto it1 = upper_bound(inorderList.begin(), inorderList.end(), q);
            int pred = (it1 == inorderList.begin()) ? -1 : *(--it1);

            auto it2 = lower_bound(inorderList.begin(), inorderList.end(), q);
            int succ = (it2 == inorderList.end()) ? -1 : *it2;

            result.push_back({pred, succ});
        }

        return result;
    }
};


int main() {

    return 0;
}