#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void left_view(TreeNode* root, vector<int> &result, unordered_set<int> &visited){
        if(!root) return;
        if(!visited.count(root->data)){
            result.push_back(root->data);
            visited.insert(root->data);
        }
        if(root->left){
            left_view(root->left, result, visited);
        } else{
            left_view(root->right, result, visited);
        }
    }
    void rght_view(TreeNode* root, vector<int> &result, unordered_set<int> &visited){
        if(!root) return;
        if(root->right){
            left_view(root->right, result, visited);
        } else{
            left_view(root->left, result, visited);
        }
        if(!visited.count(root->data)){
            result.push_back(root->data);
            visited.insert(root->data);
        }
    }
    void bottom_view(TreeNode* root, vector<int> &result, unordered_set<int> &visited){
        if(!root) return;
        if(root->left == NULL and root->right == NULL){
            if(!visited.count(root->data)){
                result.push_back(root->data);
                visited.insert(root->data);
            }
        }
        bottom_view(root->left, result, visited);
        bottom_view(root->right, result, visited);
    }
    
    vector<int> boundary(TreeNode* root){
        vector<int> result;
        unordered_set<int> visited;
        if(!root) return {};
        result.push_back(root->data);
        visited.insert(root->data);
        left_view(root->left, result, visited);
        rght_view(root->right, result, visited);
        bottom_view(root, result, visited);

        return result;
    }
};


int main() {

    return 0;
}