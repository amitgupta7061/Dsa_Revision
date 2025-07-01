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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, long long>> dq;
        dq.push_back({root, 0});
        long long result = 0;

        while (!dq.empty()) {
            int size = dq.size();
            long long left = dq.front().second;
            long long right = dq.back().second;
            result = max(result, right - left + 1);

            for (int i = 0; i < size; ++i) {
                auto [node, index] = dq.front(); dq.pop_front();
                index -= left; 

                if (node->left) dq.push_back({node->left, 2 * index + 1});
                if (node->right) dq.push_back({node->right, 2 * index + 2});
            }
        }

        return result;
    }
};



int main() {

    return 0;
}