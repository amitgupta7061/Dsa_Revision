#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q; q.push(root);
        string result = "";
        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            if(node == NULL) result += "#,";
            else result += (to_string(node->val) + ',');

            if(node){
                q.push(node->left); 
                q.push(node->right);
            }
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        stringstream ss(data);
        string str;

        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q; q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            getline(ss, str, ',');
            if(str == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(ss, str, ',');
            if(str == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};


int main() {

    return 0;
}