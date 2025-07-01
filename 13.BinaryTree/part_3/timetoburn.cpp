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
    void mapparentToeachNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root->left){
            parent[root->left] = root;
            mapparentToeachNode(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            mapparentToeachNode(root->right, parent);
        }
    }
    TreeNode* searchinNode(TreeNode* root, int target) {
        if (!root) return NULL;
        if (root->val == target) return root;
        
        TreeNode* left = searchinNode(root->left, target);
        if (left) return left;
        
        return searchinNode(root->right, target);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        mapparentToeachNode(root, parent);
        unordered_set<TreeNode*> visited;

        TreeNode* node = searchinNode(root, start);
        queue<pair<TreeNode*, int>> q;
        int time = 0;
        q.push({node, time});
        visited.insert(node);

        while(q.size()){
            for(int i = q.size(); i > 0; i--){
                auto [curr, currtime] = q.front(); q.pop();
                time = max(time, currtime);
                if(curr->left and !visited.count(curr->left)){
                    q.push({curr->left, time+1});
                    visited.insert(curr->left);
                }
                if(curr->right and !visited.count(curr->right)){
                    q.push({curr->right, time+1});
                    visited.insert(curr->right);
                }
                if(parent.count(curr) and !visited.count(parent[curr])){
                    q.push({parent[curr], time+1});
                    visited.insert(parent[curr]);
                }
            }
        }
        return time;
    }
};


int main() {

    return 0;
}