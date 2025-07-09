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
    void f(TreeNode* root, unordered_map<int, int> &freq, int &maxi){
        if(!root) return;
        freq[root->val]++;
        maxi = max(maxi, freq[root->val]);
        f(root->left, freq, maxi);
        f(root->right, freq, maxi);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        int maxi = 0;
        f(root, freq, maxi);
        vector<int> result;
        for(auto it : freq){
            if(it.second == maxi) result.push_back(it.first);
        }
        return result;
    }
};

int main() {

    return 0;
}