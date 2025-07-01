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
    vector<int> topView(TreeNode* root) {
        map<int, int> map;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(q.size()){
            auto [node, ind] = q.front(); q.pop();
            if(!map.count(ind)) map[ind] = node->val;

            if(node->left) q.push({node->left, ind-1});
            if(node->right) q.push({node->right, ind+1});
        }

        vector<int> result;
        for(auto it : map){
            result.push_back(it.second);
        }
        return result;
    }
};

int main() {

    return 0;
}